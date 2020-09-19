```cpp

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int capacity = *max_element(A.begin(), A.end());
    vector<int> dp(capacity + 1, 1e9);
    dp[0] = 0;
    for(int i= 0; i < B.size(); ++i) {
        for(int j = B[i]; j <= capacity; ++j) {
            dp[j] = min(dp[j], dp[j-B[i]] + C[i]);
        }
    }
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        ans += dp[A[i]];
    }
    return ans;
}
```

```cpp

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int max_cap = *max_element(A.begin(), A.end());
    
    int n = B.size();
    vector<vector<int>> dp(n+1, vector<int>(max_cap + 1, 0));
    for(int i = 1; i <= max_cap; ++i) {
        dp[0][i] = INT_MAX/2;
    }
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= max_cap; ++j) {
            if(j >= B[i-1]) {
                dp[i][j] = min({dp[i-1][j], dp[i-1][j - B[i-1]] + C[i-1],
                    dp[i][j - B[i-1]] + C[i-1]});
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        ans += dp[n][A[i]];
    }
    return ans;

}
```
