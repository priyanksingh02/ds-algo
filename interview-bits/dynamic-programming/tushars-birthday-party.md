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
