```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_reach = 0;
        for(int i = 0; i < nums.size() && i <= can_reach; ++i) {
            can_reach = max(can_reach, nums[i] + i);
        }
        return can_reach + 1 >= nums.size();
    }
};
```
