```cpp
int Solution::solve(vector<int> &A) {
    int n = A.size();
    set<int> s;
    vector<int> row;
    for(int i = 0; i < n; ++i) {
        if(row.empty())
            s.insert(A[i]);
        else {
            for(auto & x: row) {
                s.insert(abs(x - A[i]));
                s.insert(abs(x + A[i]));
            }
        }
        row.clear();
        for(auto & x: s)
            row.push_back(x);
        s.clear();
    }
    return row[0];
}
```
