```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> sqs;
        for(int i = 1; (long)i * i <= n; ++i) {
            sqs.push_back(i*i);
        }
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < sqs.size() && sqs[j] <= i; ++j) {
                dp[i] = min(dp[i],1+dp[i-sqs[j]]);
            }
        }
        return dp[n];
    }
};
```
