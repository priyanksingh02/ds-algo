```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        int n = needle.size();
        for(int i = n - 1; i < haystack.size(); ++i) {
            if(needle.back() == haystack[i]) {
                bool match = true;
                for(int j = 1; j < n; ++j) {
                    if(haystack[i-j] != needle[n-1-j]) {
                        match = false;
                        break;                        
                    }
                }
                if(match)
                    return i-n+1;
            }
        }
        return -1;
    }
};
```
