## Unique binary search trees II
See Catalan Number;
```cpp
int Solution::numTrees(int A) {
    vector<int> dp(A+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= A; ++i) {
        for(int j = 0; j < i; ++j) {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp.back();
}
```
