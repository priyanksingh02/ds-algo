```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1+amount, 1e9);
        dp[0] = 0;
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 0; j < coins.size(); ++j) { 
                if(i >= coins[j]) {
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
        }
        return (dp[amount] == 1e9)?-1:dp[amount];
    }
};
```
