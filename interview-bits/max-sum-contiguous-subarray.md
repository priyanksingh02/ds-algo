```cpp

int Solution::maxSubArray(const vector<int> &A) {
    int maxsum = INT_MIN;
    int cursum = 0;
    for(int i =0; i < A.size(); ++i) {
        cursum = max(cursum+A[i], A[i]);
        maxsum = max(maxsum, cursum);
    }
    return maxsum;
}
```
