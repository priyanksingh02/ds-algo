```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        vector<int> count(255, 0);
        int maxlen = 0;
        while(i < n) {
            count[s[i]]++;
            while(count[s[i]] > 1) {
                count[s[j]]--;
                j++;
            }
            maxlen = max(maxlen, i-j+1);
            i++;
        }
        return maxlen;
    }
};
```
