```cpp
int Solution::solve(int A) {
    return __builtin_ctz(A);
}
```
```cpp
int Solution::solve(int A) {
    return log2(A & (-A));
}
```
```cpp
int Solution::solve(int A) {
    return log2(A^(A&(A-1)));
}
```
```cpp

int Solution::solve(int A) {
    return log2(A&(~(A-1))) ;
}

```
```cpp

int Solution::solve(int A) {
    if(A == 0)
        return 0;
    int count = 0;
    for(int i = 0; i < 32; ++i) {
        if(A & (1 << i))
            break;
        count++;
    }
    return count;
}
```
