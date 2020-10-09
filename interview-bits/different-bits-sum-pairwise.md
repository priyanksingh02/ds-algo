```cpp
int Solution::cntBits(vector<int> &A) {
    const int mod = 1e9 + 7;
    int ans = 0;
    for(int i = 0; i < 32; ++i) {
        int zero = 0;
        int one = 0;
        for(int j = 0; j < A.size(); ++j) {
            if((A[j] & (1<< i)) == 0)
                ++zero;
            else
                ++one;
        }
        ans += ((long long)one * zero)% mod;
        ans %= mod;
    }
    ans <<= 1;
    return ans%mod;
}
```

```cpp

int Solution::cntBits(vector<int> &A) {
    const int mod = 1e9 + 7;
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < 32; ++i) {
        int one = 0;
        for(int j = 0; j < A.size(); ++j) {
            if((A[j]&(1<<i)))
                ++one;
        }
        int zero = n - one;
        ans = (ans + ((long)one*zero)%mod)%mod;
    }
    return (ans*2)%mod;
}
```
