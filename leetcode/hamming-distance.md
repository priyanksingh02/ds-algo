```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y);
    }
};
```

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int count = 0;
        while(n) {
            n = n & n - 1;
            ++count;
        }
        return count;
    }
};
```
