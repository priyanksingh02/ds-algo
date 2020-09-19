```cpp

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int> (3, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) {
            dp[i][j] = A[i-1][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
        }
    }
    return min({dp[n][0], dp[n][1], dp[n][2]});
}
```
