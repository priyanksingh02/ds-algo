```cpp
int Solution::solve(vector<vector<int> > &A) {
    if(A.empty())
        return 0;
    vector<int> dp(A.size(), 1);
    int maxlen = 1;
    for(int i = 1; i < A.size(); ++i) {
        for(int j = 0; j< i; ++j) {
            if(A[i][0] > A[j][1]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxlen = max(dp[i], maxlen);
    }
    return maxlen;
}
```
