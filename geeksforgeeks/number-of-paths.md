```cpp
long long numberOfPaths(int m, int n) {
  vector<vector<long long>> g(m, vector<long long> (n, 1));
  for(int i = 1; i< m; ++i) {
    for(int j = 1; j < n; ++j) {
      g[i][j] = g[i-1][j] + g[i][j-1];
    }
  }
  return g[m-1][n-1];
}

```
