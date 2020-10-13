## Subsets II
```cpp

void gen(vector<int> & A, int i , vector<int> & cur, set<vector<int>> & ans) {
    ans.insert(cur);
    for(int k = i; k < A.size(); ++k) {
        cur.push_back(A[k]);
        gen(A, k+1, cur, ans);
        cur.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    set<vector<int>> ans;
    vector<int> cur;
    gen(A, 0, cur, ans);
    return {ans.begin(), ans.end()};
}
```
```cpp

void gen(vector<int> & A, int i , vector<int> & cur, set<vector<int>> & ans) {
    if( i == A.size()) {
        ans.insert(cur);
        return ;
    }
    cur.push_back(A[i]);
    gen(A, i+1, cur, ans);
    cur.pop_back();
    gen(A, i+1, cur, ans);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    set<vector<int>> ans;
    vector<int> cur;
    gen(A, 0, cur, ans);
    return {ans.begin(), ans.end()};
}
```
