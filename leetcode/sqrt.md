```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int low = 1;
        int high = x;
        int best = low;
        while(low <= high) {
            int mid = low + (high - low >> 1);
            if((long long)mid * mid <= x) {
                best = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return best;
    }
};
```
