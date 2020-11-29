```cpp
int Solution::solve(int a, int b) {
   int ans = 0;
   int dif = b - a;
   int sum = a + b;
   for(int i = 1;i <= 8; ++i) {
     if(i + dif >= 1&& i + dif <= 8) {
       ++ans;
     }
     if(sum - i >= 1 && sum - i <= 8) {
       ++ans;
     }
   }
   return ans-2;
}
```
```cpp
int Solution::solve(int A, int B) {
    int ans = 0;
    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) {
            if(A - B == i - j) {
                ++ans;
            }
            if(A + B == i + j) {
                ++ans;
            }
        }
    }
    return ans - 2;
}
```
