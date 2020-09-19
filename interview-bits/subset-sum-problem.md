```cpp
#include <numeric>

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int sum = accumulate(A.begin(), A.end(), 0);
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(int i = 0; i < n; ++i) {
        for(int j = sum; j >= 0; --j) {
            if(dp[j]) {
                dp[j+A[i]] = true;
            }
        }
    }
    if(B <= sum && B >= 0)
        return dp[B];
    return false;
}
```
