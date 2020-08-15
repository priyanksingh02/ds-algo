```cpp

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A.front().size();
    vector<int> dp(n, 0);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < i - 1; ++j) {
            sum = max(sum, dp[j]);
        }
        dp[i] = sum + max(A[0][i],A[1][i]);
        ans = max(ans,dp[i]);
    }
    return ans;
}

```
