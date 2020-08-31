Idea: LCS(A,A)
Exception: letters can't be equal at same position
```cpp

int Solution::anytwo(string A) {
    int l = A.size();
    vector<vector<int>> dp(l+1, vector<int> (l+1 , 0));
    for(int i = 1; i <= l; ++i) {
        for(int j = 1; j <= l; ++j) {
            if(i!=j && A[i-1] == A[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l][l] > 1;
}
```
