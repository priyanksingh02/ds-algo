```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(i+1 == nums[i] or nums[i] <= 0 or nums[i] > n) {
                continue;
            }
            if(nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
                --i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i+1 != nums[i]) {
                return i+1;
            }
        }
        return n+1;
    }
};
```
