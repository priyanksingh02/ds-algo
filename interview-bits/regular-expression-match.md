```cpp

int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
    dp[0][0] = true;
    for(int i = 0; i<m; ++i) {
        if(B[i] == '*') {
            dp[i+1][0] = true;
        }
        else {
            break;
        }
    }
    for(int i =1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(A[j-1] == B[i-1] or B[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if(B[i-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    return dp[m][n];
}
```
