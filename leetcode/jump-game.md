## Jump Game I
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
## Jump Game II
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int can_reach = 0, will_reach = 0;
        int steps = 0;
        for(int i = 0; i < nums.size(); ++i) {
            can_reach = max(can_reach, nums[i] + i);
            if(i + 1 == nums.size())
                return steps;
            if(i == will_reach) {
                if(i == can_reach)
                    return -1;
                ++steps;
                will_reach = can_reach;
            }
        }
        return steps;
    }
};
```
