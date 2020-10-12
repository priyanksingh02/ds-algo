```cpp
vector<vector<int> > Solution::fourSum(vector<int> &A, int target) {
    set<vector<int>> ans;
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < n ; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int k = j + 1;
            int l = n- 1;
            int ct = target - A[i] - A[j]; // current target
            while(k < l) {
                int cs = A[k] + A[l];
                if(ct == cs) {
                    ans.insert({A[i], A[j], A[k], A[l]});
                    k++; l--;
                }
                else if(ct < cs) {
                    l--;
                }
                else {
                    k++;
                }
            }
        }
    }
    return {ans.begin(), ans.end()};
}
```

```cpp

bool unique(vector<int> v) {
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); ++i) {
        if(v[i] == v[i-1])
            return false;
    }
    return true;
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n= A.size();
    unordered_map<int, vector<pair<int,int>>> m;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            m[A[i]+A[j]].push_back({i,j});
        }
    }
    set<vector<int>> s;
    for(auto & x: m) {
        if(m.count(B - x.first)) {
            for(auto & p: x.second) {
                for(auto & q: m[B-x.first]) {
                    if(!unique({p.first, p.second, q.first, q.second}))
                        continue;
                    vector<int> tmp = {A[p.first], A[p.second], A[q.first], A[q.second] };
                    sort(tmp.begin(), tmp.end());
                    s.insert(tmp);
                }
            }
        }
    }
    return {s.begin(), s.end()};
}
```
