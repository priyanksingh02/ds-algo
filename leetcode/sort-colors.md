```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        for(int k = 0; k <= j; ++k) {
            if(nums[k] == 2) {
                swap(nums[k], nums[j--]);
                k--;
            }
            else if(nums[k] == 0) {
                nums[i++] = nums[k]; 
            }
        }
        while(i <= j) {
            nums[i++] = 1;
        }
    }
};
```
