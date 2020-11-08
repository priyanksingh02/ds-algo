Similar to `Coin Change problem` in geeksforgeeks.
```cpp
int Solution::coinchange2(vector<int> &coins, int n) {
    const int M = 1e6+7;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); ++i) {
        for(int j = coins[i]; j <= n; ++j) {
            dp[j] += dp[j-coins[i]];
            dp[j] %= M;
        }
    }
    return dp[n];
}
```

