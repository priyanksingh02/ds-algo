```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = -1;
        int freq = 0;
        for(int i = 0; i< nums.size(); ++i) {
            if(freq == 0) {
                major = nums[i];
                freq = 1;
            }
            else if(nums[i] == major) {
                freq++;
            }
            else {
                --freq;
            }
        }
        return major;
    }
};
```
