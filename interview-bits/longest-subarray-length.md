```cpp

int Solution::solve(vector<int> &A) {
    int pre = 0;
    unordered_map<int, int> m;
    m[0] = 0;
    int maxlen = 0;
    for(int i = 0; i < A.size(); ++i) {
        pre += (A[i])?1:-1;
        if(m.count(pre - 1)) {
            maxlen = max(maxlen, i + 1 - m[pre - 1]);
        }
        if(m.count(pre) == 0)
            m[pre] = i+1;
    }
    return maxlen;
}
```
