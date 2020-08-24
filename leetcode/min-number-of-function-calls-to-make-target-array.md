```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int add = 0;
        int mul = 0;
        for(auto x: nums) {
            int cur_mul = 0;
            while(x) {
                if(x & 1) {
                    ++add;
                    --x;
                }
                else {
                    x /= 2;
                    ++cur_mul;
                }
            }
            mul = max(mul, cur_mul);
        }
        return add+mul;
    }
};
```
