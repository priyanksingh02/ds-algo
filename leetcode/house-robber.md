```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int profit = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i - 1; j++)
                dp[i] = max(dp[i], dp[j]);
            dp[i]+= nums[i];
            profit = max(profit, dp[i]);
        }
        return profit;
    }
};
```
