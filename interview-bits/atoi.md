```cpp
int Solution::atoi(const string A) {
    long res = 0;
    int n = A.size();
    int i = 0;
    while(i < n && A[i] == ' ')
        i++;
    bool neg = false;
    if(A[i] == '+')
        i++;
    if(A[i] == '-') {
        neg = true;
        i++;
    }
    while(i < n && isdigit(A[i])) {
        res = res*10 + A[i] - '0';
        if(!neg && res > INT_MAX)
            return INT_MAX;
        if(neg && res > INT_MAX)
            return INT_MIN;
        i++;
    }
    if(neg)
        return -res;
    else
        return res;
}
```
```cpp
int Solution::atoi(const string A) {
    long res= 0;
    bool sign = false;
    bool space = true;
    bool neg = false;
    for(int i = 0; i < A.size(); ++i) {
        if(space and A[i] == ' ') {
            continue;
        }
        space = false;
        if(!sign && (A[i] == '+' or A[i] == '-')) {
            sign = true;
            if(A[i] == '-') {
                neg = true;
            }
            continue;
        }
        if(isdigit(A[i])) {
            res = res*10 + A[i] - '0';
            if(!neg && res > INT_MAX)
                return INT_MAX;
            if(neg && -res < INT_MIN)
                return INT_MIN;
            continue;
        }
        break;
    }
    if(neg)
        return -res;
    return res;
}
```
