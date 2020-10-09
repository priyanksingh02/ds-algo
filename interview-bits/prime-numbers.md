```cpp

vector<int> Solution::sieve(int A) {
    vector<bool> prime(A+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= A; ++i) {
        if(prime[i]) {
            for(int j = i*i; j <=A; j+= i) {
                prime[j] = false;
            }
        }
    }
    vector<int> ans;
    for(int i = 2; i <= A; ++i) {
        if(prime[i])
            ans.push_back(i);
    }
    return ans;
}
```
