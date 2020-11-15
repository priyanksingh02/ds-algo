```cpp
int maxSubarraySum(int arr[], int n) {
    long cur_sum = 0, max_sum = INT_MIN;
    for(int i= 0; i < n; ++i) {
        cur_sum = max(cur_sum + arr[i], (long)arr[i]);
        max_sum = max(max_sum , cur_sum);
    }
    return max_sum;
}

```
