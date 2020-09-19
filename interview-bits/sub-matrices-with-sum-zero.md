```cpp
int count(const vector<int> & row) {
    unordered_map<int,int> m;
    m[0] = 1;
    int ans = 0;
    int prefix = 0;
    for(int i = 0; i < row.size(); ++i) {
        prefix += row[i];
        if(m.find(prefix) != m.end())
            ans += m[prefix];
        m[prefix]++;
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() || A.front().empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    int ans  = 0;
    for(int i = 0; i < m; ++i) {
        vector<int> row(n, 0);
        for(int j = i; j < m; ++j) {
            for(int k = 0; k < n; ++k) {
                row[k] += A[j][k];
            }
            ans += count(row);
        }
    }
    return ans;
}
```
