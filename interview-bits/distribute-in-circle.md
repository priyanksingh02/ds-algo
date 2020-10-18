```cpp

int Solution::solve(int A, int B, int C) {
    A %= B;
    C += A - 1;
    C = (C + B)%B;
    return C;
}
```
