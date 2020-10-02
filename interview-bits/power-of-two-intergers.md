```cpp
int Solution::isPower(int A) {
    if(A == 1)
        return true;
    for(int i = 2; i*i <= A; ++i) {
        int c = log(A)/log(i);
        if(pow(i, c) == A)
            return true;
    }
    return false;
}
```

```cpp
int Solution::isPower(int A) {
    const int MAX = 1e6+10;
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    int lim = sqrt(MAX);
    for(int i = 2; i <= lim; ++i) {
        if(is_prime[i]) {
            for(int j = i*i; j < MAX; j+=i)
                is_prime[j] = false;
        }
    }
    if(A < MAX and is_prime[A])
        return false;
    int ans = INT_MAX;
    for(int i = 2; i < MAX && i <= A; ++i) {
        if(is_prime[i]) {
            int power = 0;
            while(A%i == 0) {
                A/= i;
                power++;
            }
            if(ans == INT_MAX)
                ans = power;
            else
                ans = __gcd(ans, power);
            if(ans == 1)
                return false;
            if(A == 1)
                break;
        }
    }
    return true;
}
```
