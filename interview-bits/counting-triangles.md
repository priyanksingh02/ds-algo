```cpp

int Solution::nTriang(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = 0;
    const int M = 1e9 + 7;
    int n = A.size();
    for(int i = 0; i < n - 2; ++i) {
        for(int j = i+1; j < n - 1; ++j) {
            int cnt = lower_bound(A.begin(), A.end(), A[i] + A[j]) - A.begin();
            cnt = max(0, cnt - j - 1);
            ans = (ans + cnt)%M;
        }
    }
    return ans;
}
```
