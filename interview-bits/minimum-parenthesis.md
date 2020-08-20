```cpp
int Solution::solve(string A) {
    int level = 0;
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == '(') {
            ++level;
        }
        else {
            --level;
            if(level < 0) {
                ++ans;
                level = 0;
            }
        }
    }
    ans+= level;
    return ans;
}
```
