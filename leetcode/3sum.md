```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i =0; i < n; ++i) {

            int j = i+1;
            int k = n-1;
            int target = -nums[i];
            while(j < k) {
                int sum = nums[j] + nums[k];
                if(sum == target) {
                    s.insert({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                }
                else if(sum < target)
                    ++j;
                else
                    --k;
            }
        }
        return {s.begin(),s.end()};
    }
};
```
