```cpp
int Solution::numDecodings(string A) {
    const int mod = 1e9 + 7;
    int n = A.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        //single digit always qualifies
        if(A[i] != '0')
            dp[i+1] = dp[i];
        if(i > 0 && A[i-1] != '0' && stoi(A.substr(i-1, 2)) <= 26)
            dp[i+1] = (dp[i+1]+dp[i-1])%mod;
    }
    return dp[n];
}
```
