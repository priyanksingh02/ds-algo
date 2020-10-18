```cpp

int Solution::nchoc(int A, vector<int> &B) {
    int ans = 0;
    priority_queue<int> pq;
    const int mod = 1e9 + 7;
    for(int x: B) {
        pq.push(x);
    }
    while(A--) {
        int l = pq.top();
        pq.pop();
        pq.push(l/2);
        ans = ((long)ans + l)%mod;
    }
    return ans;
}
```
