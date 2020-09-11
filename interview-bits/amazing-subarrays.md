```cpp
unordered_set<char> m = {'a','e','i','o','u'};

bool vowel(char c) {
    return m.count(tolower(c));
}

int Solution::solve(string A) {
    const int mod = 1e4 + 3;
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(vowel(A[i])) {
            ans += (n - i);
            ans %= mod;
        }
    }
    return ans;
}
```
