```cpp
int Solution::minimumTotal(vector<vector<int>> & g) {
    if(g.empty())
        return 0;
    vector<int> cur, prev;
    int n = g.size();
    prev.push_back(g[0][0]);
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0)
                cur.push_back(prev.front() + g[i][j]);
            else if(j == i)
                cur.push_back(prev.back() + g[i][j]);
            else {
                cur.push_back(min(prev[j-1],prev[j]) + g[i][j]);
            }
        }
        prev = move(cur);
    }
    return *min_element(prev.begin(), prev.end());
}
```
