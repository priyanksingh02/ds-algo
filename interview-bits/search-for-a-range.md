```cpp
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    auto left = lower_bound(A.begin(), A.end(), B);
    auto right = upper_bound(A.begin(), A.end(), B);
    if(left == right)
        return {-1,-1};
    else {
        int a = left - A.begin();
        int b = right - A.begin() - 1;
        return {a, b};
    }
}
```

```cpp
vector<int> Solution::searchRange(const vector<int> &A, int B) {
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
    if(A[low] != B)
        return {-1,-1}; // not found
    int left = low;
    int right = low;
    low = 0;
    high = (int)A.size() - 1;
    while(low <= high) {
        int mid = low + (high - low >> 1);
        if(A[mid] <= B) {
            right = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return {left, right};
}
```
