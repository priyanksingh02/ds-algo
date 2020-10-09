```cpp

int Solution::solve(int A, int B, int C, int D) {
    if(A == B) {
        return C == D;
    }
    if(A == C)
        return B == D;
    if(A == D) {
        return C == D;
    }
    return false;
}
```
