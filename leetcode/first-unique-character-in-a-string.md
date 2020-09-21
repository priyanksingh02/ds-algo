```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> seen;
        for(auto & c: s)
            seen[c]++;
        for(int i = 0; i < s.size(); ++i) {
            if(seen[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
```
