```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(255, 0);
        bool odd = false;
        for(int i = 0; i < s.size(); ++i) {
            count[s[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < count.size(); ++i) {
            if(count[i] & 1) {
                odd = true;
                ans += count[i] - 1;
            }
            else {
                ans += count[i];
            }
        }
        if(odd)
            ++ans;
        return ans;
    }
};

```
