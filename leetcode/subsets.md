## Subsets
```cpp
class Solution {
    vector<vector<int>> ans;
public:
    void gen(vector<int> & nums, int pos, vector<int> & cur) {
        if(nums.size() == pos) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[pos]);
        gen(nums, pos+1, cur);
        cur.pop_back();
        gen(nums, pos+1, cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<int> cur;
        gen(nums, 0, cur);
        return ans;
    }
};
```
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
