```cpp

int Solution::isPrime(int A) {
    if(A < 2)
        return false;
    int limit = sqrt(A);
    for(int i = 2; i <= limit; i++)
        if(A%i == 0)
            return false;
    return true;
}
```
