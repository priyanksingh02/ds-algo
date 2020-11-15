```cpp
int countTriplet(int arr[], int n) {
    sort(arr, arr+n, greater<int>());
    int ans  = 0;
    for(int i = 0; i + 1 < n; ++i) {
        int j = i + 1; 
        int k = n-1;
        while(j < k) {
            long sum = (long)arr[j] + arr[k];
            if(sum == arr[i]) {
                ++ans;
                j++;
                k--;
            }
            else if(sum < arr[i]) {
                k--;
            }
            else {
                j++;
            }
        }
    }
    return ans;
}
```
