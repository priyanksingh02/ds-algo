```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
```

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};

```

