```cpp
void heapify(int arr[], int i, int m) {
    int left = (i<<1)+1;
    int right = left + 1;
    int min_pos = i;
    if(left < m && arr[left] < arr[min_pos])
        min_pos = left;
    if(right < m && arr[right] < arr[min_pos])
        min_pos = right;
    if(i != min_pos) {
        swap(arr[i], arr[min_pos]);
        heapify(arr, min_pos, m);
    }
}

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    for(int i = 0; i < n; ++i) {
        if(arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            heapify(arr2, 0, m);
        }
    }
    sort(arr2, arr2+m);
} 
```

