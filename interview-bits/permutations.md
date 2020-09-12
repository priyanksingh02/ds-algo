```cpp

void solve(vector<int> & a,int pos, vector<vector<int>> & ans) {
    if(pos == a.size()) {
        ans.push_back(a);
        return ;
    }
    for(int i = pos; i < a.size(); ++i) {
        swap(a[pos],a[i]);
        solve(a, pos + 1, ans);
        swap(a[pos],a[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    solve(A, 0, ans);
    return ans;
}
```
