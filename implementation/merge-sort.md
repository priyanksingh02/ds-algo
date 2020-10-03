## Using Vector
```cpp
void merge(vector<int> & arr, int low, int mid, int high) {
  int l1 = mid - low + 1;
  int l2 = high - mid;
  vector<int> a (l1) , b(l2);
  for(int i = 0; i < l1; ++i)
    a[i] = arr[i+low];
  for(int i = 0; i < l2; ++i)
    b[i] = arr[i+mid+1];
  a.push_back(INT_MAX);
  b.push_back(INT_MAX);
  int i = 0, j = 0;
  for(int k = low; k <= high; ++k) {
    arr[k] = (a[i] < b[j])?a[i++]:b[j++];
  }
}

void merge_sort(vector<int> & arr, int low, int high) {
  if(low < high) {
    int mid = low + (high - low)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}
```
## Using Array
```cpp
void merge(int arr[], int low, int mid, int high) {
  int l1 = mid - low + 2;
  int l2 = high - mid + 1;
  int a[l1], b[l2];
  for(int i = 0; i + 1< l1; ++i) {
    a[i] = arr[low + i];
  }
  for(int i = 0; i + 1 < l2; ++i) {
    b[i] = arr[mid+1+i];
  }
  a[l1-1] = b[l2-1] = INT_MAX;
  int i = 0, j = 0;
  for(int k = low; k <= high; ++k) {
    arr[k] = (a[i] < b[j])?a[i++]:b[j++];
  }
}

void merge_sort(int a[], int low, int high) {
  if(low < high) {
    int mid = low + (high - low)/2;
    merge_sort(a, low, mid);
    merge_sort(a, mid+1, high);
    merge(a, low,mid, high);
  }
}

```
