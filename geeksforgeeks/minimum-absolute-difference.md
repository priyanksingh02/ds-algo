```cpp
class Solution{
    public:
    int minDiffernce(int arr[], int n) 
    { 
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        // Find all subset sum possible
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i = 0; i < n; ++i) {
            for(int j = sum - arr[i]; j >= 0; --j) {
                if(dp[j])
                    dp[j+arr[i]] = true;
            }
        }
        // assign one sum to subset 1; and calculate the difference
        int mindif = 1e9;
        for(int i = 0; i < dp.size(); ++i) {
            if(dp[i]) {
                mindif = min(mindif, abs(i - (sum-i))); // i = sum of set a; (sum - i) = sum of set b;
            }
        }
        return mindif;
    } 
};

```

