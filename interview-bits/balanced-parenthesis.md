```cpp

int Solution::solve(string A) {
    int level = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == '(')
            ++level;
        else if(--level < 0)
            return false;
    }
    return level == 0;
}
```
