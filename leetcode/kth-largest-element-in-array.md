```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos = (int)nums.size() - k;
        return search(nums, 0, (int)nums.size() - 1, pos);
    }
    
    int search(vector<int>& nums,int i, int j, int k) {
        int pivot = i - 1;
        for(int it = i; it < j; ++it) {
            if(nums[it] < nums[j]) {
                swap(nums[++pivot], nums[it]);
            }
        }
        swap(nums[++pivot], nums[j]);
        if(pivot == k) {
            return nums[pivot];
        }
        else if(pivot < k) {
            return search(nums, pivot + 1, j, k);
        }
        else {
            return search(nums, i, pivot-1, k);
        }
    }
};
```
