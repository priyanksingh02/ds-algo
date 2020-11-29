```cpp
int Solution::solve(vector<int> & num, int target) {
  int low = 0;
  int high = (int)num.size() - 1;
  while(low < high) {
    int mid = low + (high - low)/2;
    if(mid + 1 < (int)num.size() && num[mid] < num[mid+1])
      low = mid + 1;
    else
      high = mid;
  }
  int peak = low;
  low = 0;
  high = peak;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(num[mid] == target)
      return mid;
    if(num[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  low = peak + 1;
  high = (int)num.size() - 1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(num[mid] == target)
      return mid;
    if(num[mid] > target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
```
```cpp
int search(vector<int> &arr, int low, int high, int target) {
    while(low <= high) {
        int mid = low + (high - low>> 1);
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target) {
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    return -1;
}

int bsearch(vector<int> & arr, int low, int high, int target) {
    while(low <= high) {
        int mid = low + (high - low >> 1);
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target) {
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }
    return -1 ;
}

int Solution::solve(vector<int> &A, int B) {
    int peak = -1;
    int low = 0;
    int high = (int)A.size() - 1;
    while(low < high) {
        int mid = low + (high - low >> 1);
        if(mid > 0 && A[mid - 1] < A[mid]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    peak = low;
    
    int left = search(A, 0, peak, B);
    if(left != -1)
        return left;
    return bsearch(A, peak, A.size() - 1, B );
}
```
