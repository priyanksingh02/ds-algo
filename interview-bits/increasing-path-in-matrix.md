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
