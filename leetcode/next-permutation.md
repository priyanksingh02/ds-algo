```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        int i = (int)nums.size() - 2;
        while(i >= 0 and nums[i] >= nums[i+1]) {
            --i;
        }
        if(i != -1) {
            int target = nums[i];
            int j = (int)nums.size() - 1;
            while(j > i && nums[j] <= target)
                --j;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
```
