```cpp

int Solution::numSetBits(unsigned int A) {
    return __builtin_popcount(A);
}
```

```cpp

int Solution::numSetBits(unsigned int A) {

    int count = 0;
    while(A) {
        ++count;
        A = A&(A-1);
    }
    return count;
}

```
