```cpp

int Solution::lis(const vector<int> &A) {
    vector<int> dp (A.size(), 1);
    int ans = 0;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
                
        }
        ans = max(dp[i],ans);
    }
    return ans;
}

```
```cpp

int Solution::lis(const vector<int> &A) {
    vector<int> seq;
    for(int i = 0; i < A.size(); ++i) {
        if(seq.empty() or seq.back() < A[i])
            seq.push_back(A[i]);
        else {
            auto iter = lower_bound(seq.begin(), seq.end(), A[i]);
            *iter = A[i];
        }
    }
    return seq.size();
}
```
```cpp
int Solution::lis(const vector<int> &A) {
    vector<int> seq;
    for(int i = 0; i < A.size(); ++i) {
        auto iter = lower_bound(seq.begin(), seq.end(), A[i]);
        if(iter == seq.end())
            seq.push_back(A[i]);
        else
            *iter = A[i];
    }
    return seq.size();
}
```
