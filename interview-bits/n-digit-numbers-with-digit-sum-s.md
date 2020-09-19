```cpp
const int mod = 1e9 + 7;
vector<vector<int>> dp;
int count(int n, int s) {
    if(n < 0 || s < 0)
        return 0;
    if(n == 1 && 0 <= s && s <= 9)
        return 1;
    if(dp[n][s] != -1)
        return dp[n][s];
    int ans = 0;
    for(int i = 0; i <= 9; ++i) {
        ans = (ans + count(n - 1, s - i)%mod)%mod;
    }
    dp[n][s] = ans;
    return ans;
}

int Solution::solve(int N, int S) {
    int ans = 0;
    dp.clear();
    dp.resize(N+1, vector<int> (S+1, -1) );
    if(N == 1 && S <= 9 && S >= 0)
        return 1;
    for(int i = 1; i <= 9; ++i) {
        ans = (ans + count(N-1, S - i)%mod)%mod;
    }
    return ans;
}
```
