```cpp
unordered_map<int, string> m { {0, "0"}, {1, "1"},
    {2, "abc"}, {3, "def"}, {4,"ghi"}, {5,"jkl"},
    {6, "mno"}, {7, "pqrs"}, {8,"tuv"}, {9, "wxyz"}
};

void solve(string & a, int pos, string & cur, vector<string> & ans) {
    if(pos == a.size()) {
        ans.push_back(cur);
        return ;
    }
    string rec = m[a[pos] - '0'];
    for(int i = 0; i < rec.size(); ++i) {
        cur.push_back(rec[i]);
        solve(a, pos+1, cur, ans);
        cur.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    string cur;
    solve(A, 0, cur, ans );
    return ans;
}
```
