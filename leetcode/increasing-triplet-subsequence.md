```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, medium = INT_MAX;
        for(int i= 0; i < nums.size(); ++i) {
            if(nums[i] <= small) {
                small = nums[i];
            }
            else if(nums[i] <= medium ) {
                medium = nums[i];
            }
            else { // current number is greater than 2 smaller number
                // previous to it
                return true;
            }
        }
        return false;
    }
};
```
