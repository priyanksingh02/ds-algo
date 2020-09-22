```cpp

vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    for(int i = n - 2; i >= 0; --i) {
        if(A[i] < A[i+1]) {
            int j = n -1;
            while(j > i && A[j] <= A[i])
                --j;
            swap(A[i], A[j]);
            reverse(A.begin() + i + 1, A.end());
            return A;
        }
    }
    return {A.rbegin(), A.rend()};
}
```
