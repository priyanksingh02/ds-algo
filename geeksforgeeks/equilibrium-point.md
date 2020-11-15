```cpp
int equilibriumPoint(long long a[], int n) {
    long long sum = 0;
    for(int i = 0;i < n; ++i) {
        sum += a[i];
    }
    long long left = 0;
    for(int i = 0; i < n; ++i) {
        long long right = sum - left - a[i];
        if(left == right)
            return i+1;
        left += a[i];
    }
    return -1;
}
```

