`O(n)`
```cpp

int Solution::solve(vector<int> &A) {
    if(A.size() == 1)
        return A[0];
    for(int i = 0; i < A.size(); ++i) {
        if(i == 0 && A[i] >= A[i+1]) {
            return A[i];
        }
        else if(i == A.size() - 1 && A[i] >= A[i-1]) {
            return A[i];
        }
        else if(A[i] >= A[i-1] && A[i] >= A[i+1]) {
            return A[i];
        }
            
    }
    return -1; // not reached, testcase guarantees solution
}
```
Idea : If numbers are increasing, move towards right.
If numbers are decreasing, move towards left.
`O(logn)`

```cpp

int Solution::solve(vector<int> &A) {
    int low = 0;
    int high = A.size() - 1;
    while(low < high) {
        int mid = low + (high - low >> 1);
        if(mid < high && A[mid] <= A[mid+1]) 
            low = mid + 1;
        else
            high = mid;
    }
    return A[low];
}

```
