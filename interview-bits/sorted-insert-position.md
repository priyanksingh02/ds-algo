```cpp
int Solution::searchInsert(vector<int> &A, int B) {
    return lower_bound(A.begin(),A.end(), B) - A.begin();
}
```
```cpp
int Solution::searchInsert(vector<int> &A, int B) {
    int low = 0;
    int high = (int)A.size() - 1;
    while(low < high) {
        int mid = low + (high - low >> 1);
        if(A[mid] >= B) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    if(A[high] < B)
        return high + 1;
    return high;
}
```

```cpp
int Solution::searchInsert(vector<int> &A, int B) {
   int low = 0;
   int high = (int)A.size() - 1;
   int pos = A.size();
   while(low <= high) {
       int mid = low + (high - low >> 1);
       if(A[mid] >= B) {
           pos = mid;
           high = mid - 1;
       }
       else {
           low = mid + 1;
       }
   }
    return pos;
}
```
