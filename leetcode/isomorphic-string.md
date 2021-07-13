Solution: Maintain a 2-way mapping
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_to_t (256, -1);
        vector<int> t_to_s (256, -1);
        for(int i = 0; i < (int)s.size(); ++i) {
            if(s_to_t[s[i]] == -1 || s_to_t[s[i]] == t[i])
                s_to_t[s[i]] = t[i];
            else
                return false;
            if(t_to_s[t[i]] == -1 || t_to_s[t[i]] == s[i])
                t_to_s[t[i]] = s[i];
            else
                return false;
        }
        return true;
    }
};
```
