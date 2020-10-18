```cpp

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int maxtime = 0;
    for(int i = 0; i < A.size(); ++i) {
        int t = abs(A[i] - B[i]);
        maxtime = max(maxtime, t);
    }
    return maxtime;
}
```
