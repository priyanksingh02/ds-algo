```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count('z'+1, 0);
        for(auto & c: s)
            count[c]++;
        for(auto & c: t)
            count[c]--;
        for(auto & x: count)
            if(x) 
                return false;
        return true;
    }
};
```
