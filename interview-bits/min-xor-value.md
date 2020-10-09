```cpp
int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int minxor = INT_MAX;
    for(int i = 1; i < A.size(); ++i) {
        minxor = min(minxor, A[i]^A[i-1]);
    }
    return minxor;
}
```
```cpp
int solve(vector<int> & A, int low, int high, int bit) {
    if(bit < 0 && low < high)
        return 0;
    if(low >= high or bit < 0 ) {
        return INT_MAX;
    }
    if(high - low + 1 == 2) {
        return A[high]^A[low];
    }
    int pivot = high + 1;
    for(int i = low; i <= high; ++i) {
        if(A[i] & (1 << bit))  {
            pivot = i;
            break;
        }
    }
    return min(solve(A, low, pivot - 1, bit-1),solve(A, pivot, high, bit-1));
}

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    return solve(A, 0, (int)A.size() - 1, 31);
}
```
