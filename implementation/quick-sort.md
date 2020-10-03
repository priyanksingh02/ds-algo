```cpp
int partition(int arr[], int low, int high) {
  int pivot = low;
  for(int i = low; i < high; ++i) {
    if(arr[i] <= arr[high]) {
      swap(arr[i], arr[pivot++]);
    }
  }
  swap(arr[high], arr[pivot]);
  return pivot;
}

void quick_sort(int arr[], int low, int high) {
  if(low < high) {
    int p = partition(arr, low, high);
    quick_sort(arr,low,p - 1);
    quick_sort(arr,p+1, high);
  }
}
```
