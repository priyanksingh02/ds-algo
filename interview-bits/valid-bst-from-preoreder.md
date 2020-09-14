```cpp
void valid(vector<int> &arr, int lpos, int rpos, int low, int high, bool & ans) {
    if(lpos > rpos)
        return;
    if(arr[lpos] < low || arr[lpos] > high ) {
        ans = false;
        return;
    }
    int i = lpos + 1;
    for(; i <= rpos; ++i) {
        if(arr[i] > arr[lpos]) {
            break;
        }
    }
    if(ans) valid(arr, lpos + 1, i - 1, low, arr[lpos], ans);
    if(ans) valid(arr, i, rpos, arr[lpos] + 1, high, ans);
}
int Solution::solve(vector<int> &A) {
    bool ans = true;
    valid(A, 0, (int)A.size()-1, INT_MIN, INT_MAX, ans);
    return ans;
}
```
