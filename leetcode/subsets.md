## Subsets II
```cpp
 class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        long long lim = (1 << nums.size());
        for(long long i = 0; i < lim; ++i) {
            vector<int> cur;
            for(int j = 0; j < nums.size(); ++j) {
                if(i & (1 << j)) {
                    cur.push_back(nums[j]);
                }
            }
            ans.insert(cur);
        }
        return {ans.begin(), ans.end()};
    }
};
```
