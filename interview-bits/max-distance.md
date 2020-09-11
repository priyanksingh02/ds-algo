```cpp

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> nums;
    for(int i = 0; i < A.size(); ++i) {
        nums.push_back({A[i], i});
    }
    sort(nums.begin(), nums.end());
    int maxlen = 0;
    int maxelem = 0;
    int n = nums.size();
    for(int i = n - 1; i >= 0; --i) {
        maxelem = max(nums[i].second, maxelem);
        maxlen = max(maxlen, maxelem - nums[i].second);
    }
    return maxlen;
}
```
