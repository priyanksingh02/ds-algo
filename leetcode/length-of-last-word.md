```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = (int)s.size() - 1;
        while(i >= 0 && s[i] == ' ')
            i--;
        int count = 0;
        while(i >= 0 && s[i--] != ' ')
            ++count;
        return count;
    }
};
```
