```cpp
class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        string ans;
        for(int i = 0; i < s.size(); i += 3) {

            if(i + 3 < s.size())
                ans += string(s.rbegin() + i, s.rbegin() + i + 3);
            else
                ans += string(s.rbegin() + i, s.rend());
            ans += ".";
        }
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
