```cpp
const int mod = 1e6 + 3;
vector<int> f;
int fact(int i) {
    if(i <= 1)
        return 1;
    else if(f[i] != -1)
        return f[i];
    else
        return f[i] = ((long)i*fact(i-1))%mod;
}

int Solution::findRank(string A) {
    string sorted = A;
    f.resize(A.size(), -1);
    sort(sorted.begin(), sorted.end());
    // cout << sorted << endl;
    int n = sorted.size();
    int ans = 0;
    for(int i = 0; i + 1 < A.size(); ++i) {
        n--;
        int dif = lower_bound(sorted.begin(), sorted.begin()+n+1, A[i]) - sorted.begin();
        ans = (ans + ((long)dif*fact(n))%mod)%mod;
        for(int j = dif; j < n; ++j) {
            sorted[j] = sorted[j+1];
        }
        sorted[n] = A[i];
        // cout << sorted << endl;
    }
    return (ans+1)%mod;
}
```
