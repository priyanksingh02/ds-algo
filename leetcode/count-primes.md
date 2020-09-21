```cpp
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)
            return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        int lim = sqrt(n);
        for(int i =2; i <= lim; ++i) {
            if(prime[i]) {
                for(int j = i*i; j < n; j+=i)
                    prime[j] = false;
            }
        }
        int count = 0;
        for(auto x: prime)
            count += x == true;
        return count;
    }
};
```
