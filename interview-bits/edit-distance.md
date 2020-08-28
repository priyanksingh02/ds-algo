```cpp
int Solution::minDistance(string a, string b) {
    vector<vector<int>> dp(a.size() + 1, vector<int> (b.size() + 1, 0));
    for(int i = 0; i <= a.size(); ++i) {
        for(int j = 0; j <= b.size(); ++j) {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
    }
    return dp.back().back();
}
```
```cpp

int rec(string & a, int i, string & b, int j, vector<vector<int>> & cache) {
    if(i == a.size()) {
        return (int)b.size() - j;
    }
    if(j == b.size()) {
        return (int)a.size() - i;
    }
    if(cache[i][j] != -1)
        return cache[i][j];
    if(a[i] == b[j])
        return cache[i][j] = rec(a, i+1, b, j+1, cache);
    else {
        return cache[i][j] = 1 + min({rec(a, i+1, b, j, cache), rec(a, i, b, j+1, cache)
            , rec(a, i+1, b, j+1, cache)
        });
    }
}


int Solution::minDistance(string A, string B) {
    vector<vector<int>> cache(A.size(), vector<int> (B.size(), -1));
    return rec(A,0,B,0,cache);
}
```
