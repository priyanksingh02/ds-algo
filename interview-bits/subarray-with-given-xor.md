```cpp
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    int prefix = 0;
    int ans = 0;
    m[0] = 1; // default case;
    for(int i = 0; i < A.size(); ++i) {
        prefix ^= A[i];
        if(m.count(prefix ^ B)) {
            ans += m[prefix^B];
        }
        m[prefix]++;
    }
    return ans;
}
```
