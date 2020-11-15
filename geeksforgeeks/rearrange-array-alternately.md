```cpp
void rearrange(long long *arr, int n) {
    using ll = long long;
    vector<ll> ans(n);
    int i = 0, j = n - 1;
    for(int k = 0; k < n; k+= 2) {
        ans[k] = arr[j--];
        if(k+1 < n)
            ans[k+1] = arr[i++];
    }
    for(int i = 0; i < n; ++i) {
        arr[i] = ans[i];
    }
}

```

O(1) space
```cpp
void rearrange(long long *arr, int n) {
    using ll = long long ;
    ll m = arr[n-1]+1;
    int i = 0, j = n - 1;
    for(int k = 0; k < n; k+= 2) {
        arr[k] += m*(arr[j--]%m);
        if(k + 1 < n) {
            arr[k+1] += m*(arr[i++]%m);
        }
    }
    for(int i = 0; i < n; ++i) {
        arr[i] /= m;
    }
}
```
