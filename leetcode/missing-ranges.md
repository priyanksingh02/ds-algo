```cpp
class Solution {
  public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
      vector<pair<int,int>> ans;
      int start = lower, end = upper;
      for(int i = 0; i < nums.size(); ++i) {
        if(start < nums[i]) {
          ans.push_back(make_pair(start, nums[i] - 1));
        }
        start = nums[i]+1;
      }
      if(start <= upper)
        ans.push_back(make_pair(start, upper));
      vector<string> strs;
      for(auto & pr: ans) {
        if(pr.first == pr.second)
          strs.push_back(to_string(pr.first));
        else
          strs.push_back(to_string(pr.first) + "->" + to_string(pr.second));
      }
      return strs;
    }
};
```
