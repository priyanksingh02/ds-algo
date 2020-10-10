```cpp

```
TLE
```cpp

bool pal(int n) {
    int i = 31;
    while((n & (1 << i)) == 0 && i >= 0) {
        i--;
    }
    int j = 0;
    while(i > j && (bool)(n &(1 << i)) == (bool)(n &(1 <<j))) {
        i--;
        j++;
    }
    if(i <= j)
        return true;
    else
        return false;
}

int Solution::solve(int A) {
    int ans = 1;
    int count = 0;
    for(int i = 1; count < A; i+=2) {
        assert(i < (int)1e9 + 7);
        if(pal(i)) {
            ++count;
            ans=i;
        }
    }
    return ans;
}
```
