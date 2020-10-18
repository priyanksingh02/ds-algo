```cpp
int Solution::chordCnt(int n) {
    long dp[n+1] = {0};
    const int mod = 1e9 + 7;
    if(n <= 1)
        return 1;
    if(n == 2)
        return 2;
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int i= 3; i <= n; ++i) {
        for(int k = 0; k < i; ++k) {
            dp[i] = (dp[i] + dp[k]*dp[i-k-1])%mod;
        }
    }
    return dp[n];
}

```
