```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> g;
        for(auto& s: strs) {
            string clone = s;
            sort(clone.begin(), clone.end());
            g[clone].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto & x: g) {
            ans.emplace_back(x.second);
        }
        return ans;
    }
};
```
