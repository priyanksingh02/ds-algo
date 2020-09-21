## Intersection of two arrays II
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> seen1, seen2;
        for(auto & x: nums1)
            seen1[x]++;
        for(auto & x: nums2)
            seen2[x]++;
        for(auto & x: seen1) {
            if(seen2.count(x.first)) {
                int times = min(x.second, seen2[x.first]);
                while(times--)
                    ans.push_back(x.first);
            }
        }
        return ans;
    }
};
```
