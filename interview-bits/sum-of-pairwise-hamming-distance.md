```cpp
int Solution::hammingDistance(const vector<int> &A) {
    const int mod = 1e9 + 7;
    long long ans = 0;
    for(int i = 0; i < 32; ++i) {
        long long zero = 0, one = 0;
        for(int j = 0; j < A.size(); ++j) {
            if(A[j] & (1 << i))
                ++one;
            else
                ++zero;
        }
        ans += (one * zero)%mod;
        ans %= mod;
    }
    return (ans*2)%mod;
}
```
