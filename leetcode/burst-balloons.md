```cpp
class Solution {
    int dp[501][501];
public:
    
    int solve(const vector<int> & nums, int start, int end) {
        if(start > end)
            return 0;
        if(dp[start][end] > 0)
            return dp[start][end];
        int ans = 0;
        int left = (start -1 < 0)?1:nums[start-1];
        int right = (end + 1 >= nums.size())?1:nums[end+1];
        for(int i = start; i <= end; ++i) {
            ans = max(ans, left*nums[i]*right + solve(nums, start, i-1) + solve(nums, i+1, end));
        }
        dp[start][end] = ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        if(nums.empty())
            return 0;
        return solve(nums, 0, (int)nums.size() - 1);
    }
};
```
