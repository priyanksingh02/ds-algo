```cpp
class Solution {
public:
    string prefix(const string& a, const string& b) {
        string ans;
        int lim = min(a.size(), b.size());
        for(int i = 0; i < lim; ++i) {
            if(a[i] == b[i])
                ans.push_back(a[i]);
            else
                break;
        }
        return ans;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        return prefix(strs.front(), strs.back());
    }
};
```
