```cpp

class Solution {
public:
    bool checkinc(vector<int> & nums) {
        for(int i = 0;i + 1 < nums.size(); ++i) {
            if(nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
    
    bool checkPossibility(vector<int>& nums) {
        for(int i= 0;i + 1< nums.size(); ++i) {
            if(nums[i] > nums[i+1]) {
                int tmp = nums[i];
                nums[i] = nums[i+1];
                if(checkinc(nums))
                    return true;
                nums[i] = nums[i+1] = tmp;
                if(checkinc(nums))
                    return true;
                return false;
            }
        }
        return true;
    }
};
```
