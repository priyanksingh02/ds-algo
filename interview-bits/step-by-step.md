```cpp
int Solution::solve(int A) {
    A = abs(A);
    int i = 1, pos = 0;
    for(; pos < A; ++i) {
        pos += i;
    }
    if(pos == A)
        return i-1;
    else {
        int dif = pos - A;
        if(dif % 2 == 0)
            return i-1;
        else {
            dif += i; // take one step
            if(dif%2 == 0)
                return i;
            else
                return i+1;
        }
    }
}
```
