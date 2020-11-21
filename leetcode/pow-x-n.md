```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        bool neg = false;
        long pow = n;
        if(pow < 0) {
            pow = -pow;
            neg = true;            
        }
        while(pow > 0) {
            if(pow&1) {
                res = res*x;
            }
            x *= x;
            pow >>= 1;
        }
        if(neg)
            return 1/res;
        return res;
    }
};
```
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            return (1/x)*(1/myPow(x, -(n+1)));
        }
        double res = 1;
        while(n) {
            if(n&1)
                res = x*res;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};
```
