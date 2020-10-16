```cpp
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A.front().size();
    if(n < 1)
        return 0;
    if(n == 1) {
        return max(A[0][0], A[1][0]); 
    }
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) {
        dp[i] = max(A[0][i], A[1][i]);
    }
    dp[1] = max(dp[0],dp[1]);
    for(int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + dp[i]);
    }
    return max(dp[n-1], dp[n-2]);
}
```
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
