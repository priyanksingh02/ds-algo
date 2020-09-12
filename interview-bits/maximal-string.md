```cpp
void f(string & A, int cur_swap, int limit, string & ans) {
    if(cur_swap == limit)
        return;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = i+1; j < A.size(); ++j) {
            swap(A[i], A[j]);
            ans = max(ans, A);
            f(A, cur_swap+1, limit, ans);
            swap(A[i], A[j]); // make the string org
        }
    }
}

string Solution::solve(string A, int B) {
    string ans = A;
    f(A, 0, B, ans);
    return ans;
}
```
