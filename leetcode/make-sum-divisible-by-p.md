```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum= (sum+nums[i])%p;
        }
        if(sum == 0)
            return 0;
        
        int prefix = 0;
        m[0] = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i])%p;
            int f = (prefix - sum + p)%p;
            if(m.count(f) > 0) {
                ans = min(ans, i+1-m[f]);
            }
            m[prefix] = i+1;
        }
        if(ans == n)
            return -1;
        return (ans == INT_MAX)?-1:ans;
    }
};
```
