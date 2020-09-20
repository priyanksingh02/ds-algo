```cpp
vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    vector<int> row, prev;
    for(int i = 1; i <= A; ++i) {
        row.push_back(1);
        if(i > 2) {
            for(int j = 1; j < prev.size(); ++j) {
                row.push_back(prev[j] + prev[j-1]);
            }
        }
        if(i > 1)
            row.push_back(1);
        ans.push_back(row);
        prev = move(row);
    }
    return ans;
}
```
