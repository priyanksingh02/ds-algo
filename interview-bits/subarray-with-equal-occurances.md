```cpp
int Solution::solve(vector<int> &A, int B, int C) {
    int ans = 0;
    unordered_map<int, int> m;
    int cnt = 0;
    m[0] = 1;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == B)
            ++cnt;
        else if(A[i] == C)
            --cnt;
        if(m.count(cnt)) {
            ans += m[cnt];
        }
        m[cnt]++;
    }
    return ans;
}

```
