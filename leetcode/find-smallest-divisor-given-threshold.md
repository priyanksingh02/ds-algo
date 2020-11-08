```cpp
class Solution {
public:
    int sum(vector<int>&nums, int div) {
        int ans = 0;
        for(int i =0; i < nums.size(); ++i) {
            ans += ceil((double)nums[i]/div);
        }
        return ans;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low >> 1);
            if(sum(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```
