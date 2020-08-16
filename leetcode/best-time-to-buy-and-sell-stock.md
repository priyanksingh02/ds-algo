## Best time to buy and sell stock III

explaination link:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/794684/2-Solutions-or-DandC-or-State-Machine-O(n)-time-O(1)-space

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        vector<int> left(prices.size(), 0);
        vector<int> right(prices.size(), 0);
        int cur_max = prices.back();
        for(int i = prices.size() - 2; i >= 0; --i) {
            cur_max = max(cur_max, prices[i]);
            right[i] = max(right[i+1], cur_max - prices[i]);
        }
        int cur_min = prices.front();
        for(int j = 1; j < prices.size(); ++j) {
            cur_min = min(prices[j], cur_min);
            left[j] = max(left[j-1], prices[j] - cur_min);
        }
        int ans = 0;
        for(int i = 0; i < left.size(); ++i) {
            ans = max(ans, left[i]+right[i]);
        }
        return ans;
    }
};
```

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int s1 = -prices.front();
        int s2, s3, s4;
        s2 = s3 = s4 = INT_MIN;
        for(int i = 1; i< prices.size(); ++i) {
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1 + prices[i]);
            s3 = max(s3, s2 - prices[i]);
            s4 = max(s4, s3 + prices[i]);
        }
        return max(0, s4);
    }
};
```
