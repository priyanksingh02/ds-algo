```cpp
int Solution::maxProduct(const vector<int> &A) {
    int minval = 1, maxval  = 1, ans = INT_MIN;
    for(int i = 0; i < A.size(); ++i) {
        int tmpminval = min({A[i], maxval*A[i], minval*A[i]});
        maxval = max({A[i], maxval*A[i], minval*A[i]});
        minval = tmpminval;
        ans = max(maxval, ans);
    }
    return ans;
}

```
