## Regular expression II
```cpp

int Solution::isMatch(const string A, const string B) {
    int m = B.size();
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= m; ++i) {
        if(B[i-1] == '*')
            dp[0][i] = dp[0][i-2];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(A[i-1] == B[j-1] or B[j-1] == '.')
                dp[i][j] = dp[i-1][j-1];
            else if(B[j-1] == '*') {
                if(B[j-2] == A[i-1] || B[j-2] == '.')
                    dp[i][j] = dp[i][j-2] || dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-2];
            }
        }
    }
    return dp[n][m];
}
```
