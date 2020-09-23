```cpp
class Solution {
public:
    bool isHappy(int n) {
        int iter = 25;
        while(iter--) {
            int a = 0;
            while(n) {
                int digit = n%10;
                a += (digit*digit);
                n /= 10;
            }
            if(a == 1)
                return true;
            n = a;
        }
        return false;
    }
};
```
