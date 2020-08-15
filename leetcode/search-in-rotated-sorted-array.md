```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int low = 0;
        int high = nums.size()-1;
        int first = nums.front();
        while(low <= high) {
            int mid = low + (high - low >> 1);
            if(nums[mid] == target)
                return mid;
            bool mid_section = nums[mid] >= first;
            bool target_section = target >= first;
            if(mid_section == target_section) { // target and nums[mid] in same section
                if(nums[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else { // target and nums[mid] in different section
                if(mid_section) 
                    low = mid + 1; // nums[mid] in front section
                else
                    high = mid - 1; // nums[mid] in back section
            }
        }
        return -1;
    }
};

```
