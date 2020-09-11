```cpp

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    bool asize = false;
    for(int i = 0; i < n; ++i) {
        if(A[i] < 0 || A[i] == i || A[i] >= n || A[A[i]] == A[i]) {
            if(A[i] == n)
                asize = true;
            continue;
        }
        swap(A[i], A[A[i]]);
        --i;
    }
    int j = 1;
    for(; j < A.size(); ++j) {
        if(A[j] == j)
            continue;
        else
            break;
    }
    if(j == n && asize)
        return j+1; // because we ignore n while swapping
    return j;
}
```
