```cpp
void gen(int i, int k, int n, vector<int> & cur, vector<vector<int>> & ans) {
    if(cur.size() == k) {
        ans.push_back(cur);
        return;
    }
    if(i > n)
        return;
    cur.push_back(i);
    gen(i+1, k, n, cur, ans);
    cur.pop_back();
    gen(i+1, k, n, cur, ans);
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> cur;
    gen(1, k, n, cur, ans);
    return ans;
}

```
