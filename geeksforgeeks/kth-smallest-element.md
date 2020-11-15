Accepted
Time: O(N log N)
```cpp
int kthSmallest(int arr[], int l, int r, int k) {
    sort(arr+l, arr+r+1);
    return arr[k-1];
}
```
TLE
```cpp
int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    for(int i = l;i <= r; ++i) {
        pq.push(arr[i]);
        if(pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
```
TLE
```cpp
int kthSmallest(int arr[], int l, int r, int k) {
    if(l > r)
        return -1;
    int pivot = l;
    for(int i = l; i < r; ++i) {
        if(arr[i] < arr[r]) {
            swap(arr[i], arr[pivot++]);
        }
    }
    swap(arr[pivot], arr[r]);
    if(k == pivot + 1) {
        return arr[pivot];
    }
    else if(k < pivot + 1) {
        return kthSmallest(arr, l, pivot - 1, k);
    }
    else {
        return kthSmallest(arr, pivot + 1, r, k);
    }
}
```

