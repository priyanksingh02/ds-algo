
```cpp
class Solution {

  public:
    int reverse(int x) {
      long res = 0;
      long a = x;
      bool neg = x < 0;
      if(neg) {
        a = -a;
      }
      assert(a >= 0);
      while(a) {
        res = (res * 10) + (a%10);
        a /= 10;
      }
      if(res > (long)INT_MAX)
        return 0;
      if(neg) res = -res;
      return res;
    }
};
```
