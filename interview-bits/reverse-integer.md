```cpp

int Solution::reverse(int A) {
    long a = A;
    bool neg = false;
    if(A < 0) {
        neg = true;
        a = -a;
    }
    long res = 0;
    while(a) {
        res = res * 10 + (a%10);
        a /= 10;
    }
    if(res > INT_MAX)
        return 0;
    if(neg && -res < INT_MIN)
        return 0;
    if(neg) {
        return -res;
    }
    else
        return res;
}
```
