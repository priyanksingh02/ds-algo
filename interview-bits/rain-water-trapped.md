```cpp

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> left(n, 0), right(n, 0);
    int cur = 0;
    for(int i = 0; i < n; ++i) {
        left[i] = cur;
        cur = max(cur, A[i]);
    }
    cur = 0;
    for(int i = n-1; i >= 0; --i) {
        right[i] = cur;
        cur = max(cur, A[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += max(0, min(left[i], right[i]) - A[i]);
    }
    return ans;
}
```
