```cpp

int Solution::sqrt(int A) {
    if(A == 0) return 0;
    int low = 1;
    int high = A;
    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low >> 1);
        if(mid <= A / mid) {
            low = mid + 1;
            ans = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}
```
