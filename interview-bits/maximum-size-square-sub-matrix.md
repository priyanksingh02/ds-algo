```cpp
int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() || A.front().empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    int maxsz = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <=m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(A[i-1][j-1]) {
                dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
                maxsz = max(maxsz, dp[i][j]);
            }
        }
    }
    return maxsz*maxsz;
}
```
