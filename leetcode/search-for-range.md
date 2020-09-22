```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(low == high) {
            return {-1,-1};
        }
        else {
            return {low, high - 1};
        }
    }
};
```
