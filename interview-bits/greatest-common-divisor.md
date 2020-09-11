```cpp
int Solution::gcd(int A, int B) {
    return __gcd(A,B); // inbuilt function
}
```

```cpp
int Solution::gcd(int A, int B) {
    if(B == 0)
        return A;
    else
        return gcd(B, A%B);
}
```
