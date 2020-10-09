```cpp

int Solution::strStr(const string A, const string B) {
    if(B.empty())
        return -1;
    int n = A.size();
    int m = B.size();
    for(int i = m - 1; i < n; ++i) {
        if(A[i] == B.back()) {
            bool match = true;
            for(int j = 0; j < m; ++j) {
                if(A[i-j] != B[m-1-j]) {
                    match = false;
                    break;
                }
            }
            if(match)
                return i+1-m;
        }
    }
    return -1;
}
```
