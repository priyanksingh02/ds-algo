```cpp

int Solution::cpFact(int A, int B) {
    int lim  = sqrt(A);
    int ans =  1;
    for(int i = 1; i <= lim; ++i) {
        if(A%i == 0) {
            int other = A/i;
            if(__gcd(B, other) == 1)
                return other;
            if(__gcd(B, i) == 1)
                ans = max(ans, i);
        }
    }
    return ans;
}
```
```cpp

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int Solution::cpFact(int A, int B) {
    int lim  = sqrt(A);
    int ans =  1;
    for(int i = 1; i <= lim; ++i) {
        if(A%i == 0) {
            int other = A/i;
            if(gcd(B, other) == 1)
                return other;
            if(gcd(B, i) == 1)
                ans = max(ans, i);
        }
    }
    return ans;
}
```
