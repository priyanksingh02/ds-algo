```cpp


int Solution::maxProfit(const vector<int> &A) {
    int profit = 0, mxprofit = 0;
    int mx = INT_MIN, mn = INT_MAX;
    for(int i = 0; i < A.size(); ++i) {
        if(mn > A[i]) { // if elem goes below min, reset min and max
            mx = mn = A[i];
        }
        if(mx < A[i])
            mx = A[i];
        profit = mx-mn;
        mxprofit = max(profit, mxprofit);
    }
    return mxprofit;
}
```

```cpp
int Solution::maxProfit(const vector<int> &A) {
    int ans = 0;
    int max_till_now = 0;
    for(int i = A.size() - 1; i >= 0; --i) {
        max_till_now = max(max_till_now, A[i]);
        ans = max(ans, max_till_now - A[i]);
    }
    return ans;
}
```
