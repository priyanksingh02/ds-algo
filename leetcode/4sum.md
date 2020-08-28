```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n = nums.size();
        if(n == 0)
            return {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                int k = j + 1;
                int l = n - 1;
                long long ctarget = (long long)target - nums[i] - nums[j];
                while(k < l) {
                    long long sum = (long long)nums[k] + nums[l];
                    if(sum == ctarget) {
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        --l;
                    }
                    else if(sum < ctarget) {
                        k++;
                    }
                    else 
                        --l;
                }
            }
        }
        return {ans.begin(), ans.end()};
    }
};
```
