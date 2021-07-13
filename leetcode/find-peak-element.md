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
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = (int)nums.size() - 1;
        while(abs(low - high) > 1) { // ensures more than 2 elements
            int mid = low + ((high - low) >> 1);
            if(nums[mid-1] > nums[mid]) { // for 3 or more elements, mid - 1 always exists
                high = mid - 1;
            }
            else {
                low = mid;
            }
        }
        if(nums[low] > nums[high]) {
            return low;
        }
        else {
            return high;
        }
    }
};
```
