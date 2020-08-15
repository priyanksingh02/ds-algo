```cpp

int Solution::lis(const vector<int> &A) {
    vector<int> dp (A.size(), 1);
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
                
        }
        ans = max(dp[i],ans);
    }
    return ans;
}

```
