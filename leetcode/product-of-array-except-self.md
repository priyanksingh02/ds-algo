```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix (n, 1), suffix(n, 1);
        long prev =1;
        for(int i = 0; i < n; ++i) {
            prefix[i] = prev;
            prev *= nums[i];
        }
        prev= 1;
        for(int i = n-1; i >= 0; --i) {
            suffix[i] = prev;
            prev *= nums[i];
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};
```
