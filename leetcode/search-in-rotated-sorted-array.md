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
## Search in rotated array II
Idea: Remove copies of first element from back of array. This reduces the problem to version I.
Average Runtime: O(logn)
Worst Case: O(n) : if every element is equal to first element and not equal to target
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        if(nums[0] == target)
            return true;
        while(!nums.empty() and nums.back() == nums.front())
            nums.pop_back();
        if(nums.empty())
            return false;
        int front = nums[0];
        int low = 0;
        int high = (int)nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low >> 1);
            if(nums[mid] == target)
                return true;
            bool mid_section = nums[mid] >= front;
            bool target_section = target >= front;
            if(mid_section == target_section) {
                if(nums[mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else {
                if(mid_section) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
```
Runtime: O(n)
Idea : Find pivot and run two binary search on two sorted halves.

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[i-1])
                pivot = i;
            if(target == nums[i])
                return true;
        }
        return search(nums,0,pivot-1,target) || search(nums,pivot,(int)nums.size() - 1, target);
    }
    bool search(vector<int> & nums, int i, int j, int target) {
        while(i <= j) {
            int mid = i + (j - i >> 1);
            if(nums[mid] == target)
                return true;
            if(nums[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return false;
    }
};
```
