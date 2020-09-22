```cpp
class Solution {
    vector<vector<int>> ans;
public:
    void gen(vector<int>&nums, int pos) {
        if(pos == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); ++i) {
            swap(nums[i], nums[pos]);
            gen(nums, pos+1);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        gen(nums, 0);
        return ans;
    }
};
```
