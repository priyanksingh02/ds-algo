```cpp

int Solution::solve(int A) {
    int one = 1, two = 1;
    const int M = 1e9 + 7;
    if(A <= 2)
        return 1;
    for(int i = 3; i <= A; ++i) {
        int temp = (one + two)%M;
        one = two;
        two = temp;
    }
    return two;
}
```
