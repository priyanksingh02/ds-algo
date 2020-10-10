```cpp

int Solution::solve(vector<int> &A) {
    int ans = 0;
    int n = A.size();
    for(int i = 0; i < n; ++i) {
        if(((i+1)*(n-i))%2 != 0) {
            ans ^= A[i];
        }
    }
    return ans;
}
```
