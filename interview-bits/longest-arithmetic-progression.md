See solution approach to understand
```cpp
int Solution::solve(const vector<int> &A) {
    vector<vector<int>> dp(A.size(), vector<int> (A.size(), 0));
    int n = A.size();
    if(n < 2)
        return n;
    int mx = 0;
    unordered_map<int, int> pos;
    for(int i = 0; i < n -1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            dp[i][j] = 2;
            int x = 2 * A[i] - A[j];
            if(pos.count(x) > 0)
                dp[i][j] = max(dp[i][j], dp[pos[x]][i] + 1);
            mx = max(mx,dp[i][j]);
        }
        pos[A[i]] = i;
    }
    return mx;
}
```
