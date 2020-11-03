```cpp
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        // Counts with all permutations
        // for(int i = 1; i <= n; ++i) {
        //     for(int j = 0; j < m; ++j) {
        //         if(S[j] <= i) {
        //             dp[i] += dp[i-S[j]];
        //         }
        //     }
        // }

        // Counts Without permutations
        for(int i = 0; i < m; ++i) {
            for(int j = S[i]; j <= n; ++j) {
                dp[j] += dp[j-S[i]];
            }
        }
        return dp[n];
    }
};
```

