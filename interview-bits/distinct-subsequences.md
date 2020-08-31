```cpp

int Solution::numDistinct(string S, string T) {
    vector<vector<int>> dp(T.size() + 1, vector<int> (S.size() + 1, 0));
    for(int i = 0; i <= T.size(); ++i) {
        for(int j = 0; j <= S.size(); ++j) {
            if(i == 0)
                dp[i][j] = 1;
            else if(j == 0)
                dp[i][j] = 0;
            else if(T[i-1] == S[j-1]) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp.back().back();
}
```
