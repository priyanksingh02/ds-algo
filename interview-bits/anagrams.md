```cpp

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string, vector<int>> m;
    for(int i =0; i < A.size(); ++i) {
        string s = A[i];
        sort(s.begin(), s.end());
        m[s].push_back(i+1);
    }
    vector<vector<int>> ans;
    for(auto & x: m) {
        ans.emplace_back(x.second);
    }
    return ans;
}
```
