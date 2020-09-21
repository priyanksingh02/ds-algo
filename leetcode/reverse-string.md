```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = s.size()/2;
        int len = s.size();
        for(int i= 0; i < l; ++i)
            swap(s[i], s[len-1-i]);
    }
};
```
