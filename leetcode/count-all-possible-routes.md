```cpp
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(fuel + 1, vector<int> (n, 0));
        const int mod = 1e9 + 7;
        dp[0][start] = 1;
        for(int f = 0; f <= fuel; ++f) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k ) {
                    int cost = abs(locations[j] - locations[k]);
                    if(j == k || f + cost > fuel)
                        continue;
                    dp[f + cost][k] = (dp[f+cost][k] + dp[f][j])%mod;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= fuel; ++i) {
            ans = (ans + dp[i][finish])%mod;
        }
        return ans;
    }
};
```
