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
Accepted Solution:

Random Swap was the key.
```cpp
class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        return helper(arr, l, r, k-1);
    }

    int helper(int arr[], int l, int r, int k) {
        int pos = l;
        swap(arr[rand()%(r-l+1) + l], arr[r]);
        for(int i = l; i < r; ++i) {
            if(arr[i] <= arr[r]) {
                swap(arr[i], arr[pos++]);
            }
        }
        swap(arr[r], arr[pos]);
        if(pos == k) {
            return arr[pos];
        }
        else if(pos < k) {
            return helper(arr, pos+1, r, k);
        }
        else {
            return helper(arr, l, pos-1, k);
        }
    }
};
```
