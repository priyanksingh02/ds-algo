```cpp

int Solution::solve(int A, int B) {
    int ans = 0;
    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) {
            if(A - B == i - j) {
                ++ans;
            }
            if(A + B == i + j) {
                ++ans;
            }
        }
    }
    return ans - 2;
}
```
