```cpp

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> right(n, 0);
    int cur = 0;
    for(int i = n - 1; i >= 0; --i) {
        cur = max(cur, A[i]);
        right[i] = cur;
    }
    set<int> s;
    int sum = 0;
    for(int i = 0; i + 1 < n; ++i) {
        if(right[i] == A[i])
            continue;
        auto iter = s.lower_bound(A[i]);
        if(iter != s.begin()) {
            --iter;
            sum = max(sum, *iter + A[i] + right[i]);
        }
        s.insert(A[i]);
    }
    return sum;
}
```
