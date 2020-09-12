```cpp
int Solution::maxSpecialProduct(vector<int> &A) {
    const int mod = 1e9 + 7;
    stack<int> pos;
    int n = A.size();
    vector<int> left(n, 0), right (n, 0);
    for(int i = 0; i < n; ++i) {
        while(!pos.empty() && A[pos.top()] <= A[i])
            pos.pop();
        if(!pos.empty())
            left[i] = pos.top();
        pos.push(i);
    }
    while(!pos.empty()) // clear stack
        pos.pop();
    for(int i = n - 1; i >= 0; --i) {
        while(!pos.empty() && A[pos.top()] <= A[i])
            pos.pop();
        if(!pos.empty())
            right[i] = pos.top();
        pos.push(i);
    }
    long ans = 0;
    for(int i = 0; i< n; ++i) {
        ans = max(ans, (long)left[i]*right[i]);
    }
    return ans%mod;
}
```
