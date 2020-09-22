```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = (int)nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low >> 1);
            if(nums[mid] < nums[mid+1]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};
```
