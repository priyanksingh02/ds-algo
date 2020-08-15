```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto iter = lower_bound(nums.begin(),nums.end(),target);
        if(iter == nums.end() || *iter != target)
            return -1;
        return iter - nums.begin();
    }
};
```

```cpp

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low >> 1);
            if(nums[mid] == target)
                return mid;
            if(target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
```
