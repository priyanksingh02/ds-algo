```cpp

int Solution::fibsum(int A) {
    vector<long long> fibo;
    fibo.push_back(1);
    fibo.push_back(1);
    for(int i = 2; fibo.back() <= A; ++i) {
        fibo.push_back(fibo[i-1]+fibo[i-2]);
    }
    int pos = fibo.size() - 2;
    assert(pos >= 0);
    int ans = 0;
    for(int i = pos; i>=0; --i) {
        if(fibo[i] <= A) {
            ++ans;
            A-= fibo[i];
            ++i; // repeated numbers
        }
    }
    return ans;
}

```
DP solution, Only works if n < 10^6. Else `bad_alloc` exception
```cpp
int Solution::fibsum(int A) {
    vector<long long> fibo;
    fibo.push_back(1);
    fibo.push_back(1);
    for(int i = 2; fibo.back() <= A; ++i) {
        fibo.push_back(fibo[i-1]+fibo[i-2]);
    }
    vector<int> dp(A+1, 1);
    for(int i = 1; i < dp.size(); ++i) {
        auto iter = lower_bound(fibo.begin(), fibo.end(),i);
        assert(iter != fibo.end());
        if(*iter != i) {
            int pos = iter - fibo.begin();
            dp[i] = 1e9;
            for(int j = 0; j < pos; ++j) {
                dp[i] = min(dp[i], dp[i-fibo[j]] + 1);
            }
        }
    }
    return dp[A];
}
```
