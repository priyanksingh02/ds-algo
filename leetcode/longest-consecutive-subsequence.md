```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans= 0;
        unordered_set<int> s;
        for(auto & x: nums)
            s.insert(x);
        for(auto & x: s) {
            if(s.count(x-1))
                continue;
            int len = 1;
            int num = x;
            while(s.count(num+1)) {
                num++;
                len++;
            }
            ans = max(len, ans);
        }
        return ans;
    }
};
```
