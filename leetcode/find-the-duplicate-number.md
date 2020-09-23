```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i< n; ++i) {
            int pos = abs(nums[i]);
            if(nums[pos] < 0)
                return pos;
            nums[pos] = -nums[pos];
        }
        return -1;
    }
};
```
