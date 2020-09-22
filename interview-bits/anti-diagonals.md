```cpp

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    if(A.empty())
        return {};
    int n = 2*A.size() - 1;
    vector<vector<int>> ans(n);
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < A.size(); ++j) {
            ans[i+j].push_back(A[i][j]);
        }
    }
    return ans;
}
```
