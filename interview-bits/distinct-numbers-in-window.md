```cpp
vector<int> Solution::dNums(vector<int> &a, int b) {
    int n = a.size();
    if(b > n) return {};
    map<int,int> m;
    for(int i = 0; i < b; ++i) {
        m[a[i]]++;
    }
    vector<int> ans;
    ans.push_back(m.size());
    for(int i = b; i < n; ++i) {
        auto iter = m.find(a[i-b]);
        if(--iter->second == 0)
            m.erase(iter);
        m[a[i]]++;
        ans.push_back(m.size());
    }
    return ans;
}
```
