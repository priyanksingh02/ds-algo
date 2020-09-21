```cpp
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool neg = x < 0;
        if(neg) {
            if(x == INT_MIN)
                return 0;
            x = -x;
        }
        while(x) {
            long num = (long)ans*10 + (x%10);
            if(num > INT_MAX) // Overflow
                return 0;
            ans = num;
            x /= 10;
        }
        if(neg)
            return -ans;
        return ans;
    }
};
```
