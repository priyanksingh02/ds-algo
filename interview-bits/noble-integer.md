```cpp
int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    for(int i = 0; i + 1< A.size(); ++i) {
        if(n - i - 1 == A[i] && A[i] != A[i+1]) {
            return 1;
        }
    }
    if(A.back() == 0)
        return 1;
    return -1;
}
```
