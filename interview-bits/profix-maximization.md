```cpp
int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    int ans = 0;
    for(auto & x: A)
        pq.push(x);
    while(B--) {
        int val = pq.top();
        pq.pop();
        ans += val;
        if(--val > 0)
            pq.push(val);
    }
    return ans;
}
```
