```cpp

int Solution::solve(vector<vector<int> > &A) {
    
    int N = A.size();
    int M = A[0].size();
    vector<vector<int>> dp(N, vector<int> (M, 0));
    dp[0][0] = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(i > 0 && A[i-1][j] < A[i][j] && dp[i-1][j] > 0)
                dp[i][j] = 1 + dp[i-1][j];
            if(j > 0 && A[i][j-1] < A[i][j] && dp[i][j-1] > 0)
                dp[i][j] = max(dp[i][j], 1 + dp[i][j-1]);
        }
    }
    if(dp.back().back() == 0)
        return -1;
    return dp.back().back();
}
```

```cpp

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() || A.front().empty())
        return 0;
    int m = A.size();
    int n = A.front().size();
    vector<vector<int>> dp (m, vector<int> (n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i > 0 && A[i][j] > A[i-1][j] && dp[i-1][j] > 0)
                dp[i][j] = max(dp[i][j], 1 + dp[i-1][j]);
            if(j > 0 && A[i][j] > A[i][j-1] && dp[i][j-1] > 0)
                dp[i][j] = max(dp[i][j], 1 + dp[i][j-1]);
        }   
    }
    return dp[m-1][n-1]?dp[m-1][n-1]:-1;
}
```
