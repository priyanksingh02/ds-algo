```cpp
class Solution{
    public:
    int maxSumIS(int arr[], int n)
    { 
        vector<int> dp(n, 0);
        int maxsum = 0;
        for(int i = 0; i < n; ++i) {
            dp[i] = arr[i];
            for(int j = 0; j < i; ++j) {
                if(arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            maxsum = max(maxsum, dp[i]);
        }
        return maxsum;
    }
};
```

