```cpp
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // equal partition step
        int sum = 0;
        for(int i = 0;i < N; ++i)
            sum += arr[i];
        if(sum & 1) // odd sum can't be broken into two equal sums
            return false;
        sum /= 2;
        
        // Subset sum routine
        vector<vector<bool>> dp (N+1, vector<bool> (sum+1, false));
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = true;
        }
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= sum; ++j) {
                if(j < arr[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[N][sum];
    }
};

```

