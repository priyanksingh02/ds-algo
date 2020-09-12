```cpp
void sub(vector<int> &a, vector<vector<int>> &ans, vector<int> & cur, int pos) {
    ans.push_back(cur);
    for(int i = pos ; i < a.size(); ++i) {
        cur.push_back(a[i]);
        sub(a,ans, cur, i+1);
        cur.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<int> cur;
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    sub(A, ans, cur, 0);
    return ans;
}
```
