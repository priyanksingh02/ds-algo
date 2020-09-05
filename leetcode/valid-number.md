```cpp
class Solution {
public:
    bool isNumber(string s) {
        while(!s.empty() && s.back() == ' ')
            s.pop_back();
        bool wspace = true;
        bool sign = false; // neg number
        bool digit = false;
        bool num = false;
        bool e = false, dot = false;
        bool after_e = false;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ' && wspace)
                continue;
            wspace = false;
            if(s[i] == '-' && !digit) {
                sign = true;
                digit  = true;
                continue;
            }
            if(s[i] == '+' && !digit) {
                digit = true;
                continue;
            }
            digit = true;
            if((s[i] == '-' or s[i] == '+') && i > 0 && s[i-1] == 'e')
                continue;
            if(s[i] == '.' && !dot && !e) {
                dot = true;
                continue;
            }
            if(s[i] == 'e' && !e && num) {
                if(i+1 == s.size()) // number ends with e
                    return false;
                e = true;
                continue;
            }
            if(isdigit(s[i])) {
                num = true;
                if(e)
                    after_e = true;
                continue;
            }
            return false;
        }
        if(e)
            return after_e;
        return num;
    }
};
```
