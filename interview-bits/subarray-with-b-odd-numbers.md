```cpp
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    int prefix = 0;
    m[prefix] = 1;
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] & 1)
            ++ prefix;
        if(m.count(prefix - B)) {
            ans += m[prefix - B];
        }
        m[prefix]++;
    }
    return ans;
}
```
