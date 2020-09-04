```cpp
int Solution::searchInsert(vector<int> &A, int B) {
    return lower_bound(A.begin(),A.end(), B) - A.begin();
}
```
```cpp
int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

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
