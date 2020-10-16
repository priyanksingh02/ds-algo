```cpp
int Solution::numDistinct(string A, string B) {
    int m = B.size();
    int n = A.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 0; i <= n; ++i) {
        dp[0][i] = 1; // no of solution is 1; delete all chars in A to get B
    }
    for(int i = 1; i<= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(B[i-1] == A[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[m][n];
}
```
```cpp

int Solution::numDistinct(string A, string B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> lcs(m+1, vector<int> (n+1, 0));
    for(int i = 1; i <= m; ++i) {
        for(int j = 1 ; j <= n; ++j) {
            if(A[i-1] == B[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    if(lcs[m][n] != n)
        return 0;
    vector<vector<int>> path(m+1, vector<int> (n+1, 0));
    for(int i = 0; i <= n; ++i) {
        path[0][i] = 1;
    }
    for(int i = 0; i <=m; ++i) {
        path[i][0] = 1;
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(A[i-1] == B[j-1]) {
                path[i][j] = path[i-1][j-1];
                if(lcs[i][j] == lcs[i][j-1] && lcs[i][j] != 0)
                    path[i][j] += path[i][j-1];
                if(lcs[i][j] == lcs[i-1][j])
                    path[i][j] += path[i-1][j];
            }
            else {
                if(lcs[i][j] == lcs[i-1][j] && lcs[i][j] != 0)
                    path[i][j] = path[i-1][j];
                if(lcs[i][j] == lcs[i][j-1] && lcs[i][j] != 0)
                    path[i][j] = path[i][j-1];
            }
        }
    }
    return path[m][n];
}
```
