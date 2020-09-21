```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int pos = n - k;
        reverse(nums.begin(), nums.begin() + pos);
        reverse(nums.begin() + pos, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
```
