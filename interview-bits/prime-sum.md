```cpp

bool prime(int a, vector<bool> & is_prime) {
    if(a < 2)
        return false;
    if(a < is_prime.size())
        return is_prime[a];
    for(int i = 2; i < is_prime.size(); ++i) {
        if(is_prime[i] && a%i == 0)
            return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    const int MAX = 1e6 + 10;
    vector<bool> is_prime(MAX, true);
    int lim = sqrt(MAX);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= lim; ++i) {
        if(is_prime[i]) {
            for(int j = i*i; j < MAX; j+=i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i*2<= A; ++i) {
        if(prime(i,is_prime) && prime(A-i,is_prime))
            return {i, A-i};
    }
    return {};
}
```
