```cpp
class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      for(int & x: nums) {
        if (x <= 0)
          x = 1000;
      }
      for(int i = 0; i < nums.size(); ++i) {
        int x = abs(nums[i]);
        if( x <= 0 or x > nums.size() or nums[x-1] < 0)
          continue;
        nums[x-1] = -nums[x-1];
      }
      int i = 0;
      for(; i < nums.size(); ++i) {
        if(nums[i] >= 0) {
          return i + 1;
        }
      }
      return i + 1;
    }
};


```
