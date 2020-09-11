```cpp
int Solution::pow(int x, int n, int d) {
    long long res = 1;
    while(n > 0) {
        if(n&1) // n is odd
            res = (res * x)%d;
        x = ((long long)x*x)%d;
        n >>= 1;
    }
    if(res < 0)
        res += d;
    return res%d;
}
```
