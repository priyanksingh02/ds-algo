```cpp

vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int,int> m;
    int prefix = 0;
    m[0] = 0;
    int maxlen = 0, ansi = -1;
    for(int i = 0; i< A.size(); ++i) {
        prefix += A[i];
        if(m.count(prefix) && (i + 1 - m[prefix]) > maxlen) {
            maxlen = i + 1 - m[prefix];
            ansi = m[prefix];
        }
        if(!m.count(prefix))
            m[prefix] = i+1;
    }
    if(ansi == -1)
        return {};
    vector<int> ans;
    for(int i = 0; i < maxlen && ansi + i < A.size(); ++i) {
        ans.push_back(A[ansi+i]);
    }
    assert(ans.size() == maxlen);
    return ans;
}
```
