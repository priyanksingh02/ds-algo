```cpp

int Solution::uniquePaths(int A, int B) {
    vector<vector<int>> dp(1 + A, vector<int> (B + 1, 0));
    dp[0][1] = 1;
    for(int i = 1; i <= A; ++i) {
        for(int j = 1; j <= B; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[A][B];
}
```
