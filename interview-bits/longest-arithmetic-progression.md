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

```cpp

int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n <= 2)
        return n;
    vector<unordered_map<int,int>> m(n);
    int maxlen = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            int dif = A[i] - A[j];
            if(m[j].count(dif)) {
                m[i][dif] = max(m[i][dif], m[j][dif] + 1);
            }
            else {
                m[i][dif] = 2;
            }
            maxlen = max(maxlen, m[i][dif]);
        }
    }
    return maxlen;
}
```
