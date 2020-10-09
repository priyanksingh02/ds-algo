```cpp
int Solution::isNumber(const string A) {
    int n = A.size();
    int i = 0;
    bool digit = false;
    while(i < n && A[i] == ' ')
        i++;
    if(i == n)
        return false;
    if(A[i] == '+' or A[i] == '-')
        i++;
    if(i == n)
        return false;
    while(i < n && isdigit(A[i])) {
        digit = true;
        i++;
    }
    if(i == n)
        return true;
    if(A[i] == '.') {
        i++;
        if(i == n)
            return false; // nothing after decimal
        if(!isdigit(A[i]))
            return false; // no digit after decimal
    }
    while(i < n && isdigit(A[i])) {
        i++;
        digit = true;
    }
    if(i == n)
        return true;
    if(A[i] == 'e')
        i++;
    if(i == n)
        return false; // no digit after e
    if(A[i] == '+' or A[i] == '-')
        i++;
    if(i == n)
        return false;
    while(i < n && isdigit(A[i])) {
        digit = true;
        i++;
    }
    if(i == n)
        return true;
    while(i < n && isspace(A[i]))
        i++;
    if(!digit)
        return false;
    if(i == n)
        return true; // trailing whitespace
    return false;
}

```
