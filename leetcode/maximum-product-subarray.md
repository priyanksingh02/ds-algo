```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        long mn, mx, ans;
        mn = mx = ans = nums.front();
        for(int i = 1; i < nums.size(); ++i) {
            long newmn = min({(long)nums[i], mn*nums[i], mx*nums[i]});
            long newmx = max({(long)nums[i], mx*nums[i], mn*nums[i]});
            ans = max(ans, newmx);
            mx = newmx;
            mn = newmn;
        }
        return ans;
    }
};
```
