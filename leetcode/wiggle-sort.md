## Wiggle Sort II
Time: O(n)
Space: O(1)
```cpp


```
Time: O(n logn)
Space: O(n)
```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = (int)nums.size() - 1;
        int n = nums.size();
        if(j%2 == 0)
            reverse(nums.begin(), nums.begin() + n/2+ 1);
        else
            reverse(nums.begin(), nums.begin() + n/2);
        vector<int> ans;
        while(i < j) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j--]);
        }
        if(i == j) {
            ans.push_back(nums[i++]);
        }
        nums = move(ans);
    }
};

```
