```cpp
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            path[i][j] = A[i-1][j-1] + max(path[i-1][j], path[i-1][j-1]);
        }
    }
    return *max_element(path[n].begin(), path[n].end());
}
```
