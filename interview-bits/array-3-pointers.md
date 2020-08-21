```cpp

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0;
    int j = 0;
    int k = 0;
    int ans = INT_MAX;
    while(i < A.size() && j < B.size() && k < C.size()) {
        int cur_min = min({A[i], B[j], C[k]});
        int dif = max({A[i], B[j], C[k]}) - cur_min;
        ans = min(ans, dif);
        if(A[i] == cur_min) i++;
        if(B[j] == cur_min) j++;
        if(C[k] == cur_min) k++;
    }
    return ans;
}
```
