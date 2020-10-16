```cpp

vector<int> Solution::solve(vector<int> &A) {
    map<int, set<int>> m;
    for(int i = 0; i < A.size(); ++i) {
        if(m.count(A[i])) {
            int pos = *m[A[i]].begin();
            m[A[i]].erase(m[A[i]].begin());
            if(m[A[i]].empty())
                m.erase(A[i]);
            m[A[i]+1].insert(pos);
        }
        m[A[i]].insert(i);
    }
    vector<pair<int,int>> v;
    for(auto & x: m) {
        for(auto & j: x.second) {
            v.push_back({j, x.first});
        }
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    for(auto & x: v) {
        ans.push_back(x.second);
    }
    return ans;
}
```
