```cpp
class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        bool wspace = true;
        bool sign = false;
        bool neg = false;
        bool other = false;
        for(int i = 0; i < str.size(); ++i) {
            if(wspace && str[i] == ' ')
                continue;
            wspace = false;
            if(str[i] == '+' || str[i] == '-') {
                if(sign || other)
                    break;
                if(str[i] == '-')
                    neg = true;
                sign = true;
                continue;
            }
            other = true;
            if(isdigit(str[i])) {
                long res = ans;
                res = res * 10 + (str[i] - '0');
                if(!neg && res >= INT_MAX)
                    return INT_MAX;
                if(neg && -res <= INT_MIN)
                    return INT_MIN;
                ans = res;
                continue;
            }
            break;
        }
        if(neg)
            return -ans;
        return ans;
    }
};
```
