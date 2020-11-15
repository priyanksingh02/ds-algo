```cpp
bool checkTriplet(int arr[], int n) {
    const int SZ = 1e3 + 10;
    vector<bool> cnt(SZ, false);
    for(int i =0; i < n; ++i) {
        cnt[arr[i]] = true;
    }
    for(int i = 0; i < SZ; ++i) {
        if(cnt[i]) {
            for(int j = i + 1; j < SZ; ++j) {
                if(cnt[j]) {
                    int sqsum = i*i + j*j;
                    int k = sqrt(sqsum);
                    if(cnt[k] && k*k == sqsum)
                        return true;
                }
            }
        }
    }
    return false;
}
```

