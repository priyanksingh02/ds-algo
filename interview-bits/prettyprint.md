```cpp
vector<vector<int> > Solution::prettyPrint(int A) {
    int n = 2 * A - 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 0; i < A; ++i) {
        for(int j = i; j < A; ++j) {
            ans[i][j] = A-i;
            ans[j][i] = A-i;
        }
    }
    for(int i = 0; i < A; ++i) {
        for(int j = A; j < n; ++j) {
            ans[i][j] = ans[i][2*(A-1)-j];
        }
    }
    for(int i = A; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans[i][j] = ans[2*(A-1)-i][j];
        }
    }
    return ans;
}
```
