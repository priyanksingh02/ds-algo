"A" = 1
"AB" = 28
"ZY" = 701

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int count = 0;
        for(int i = 0; i< s.size(); ++i) {
            int v = s[i] - 'A' + 1;
            count = count * 26 + v;
            
        }
        return count;
    }
};
```
