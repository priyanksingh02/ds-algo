```cpp
vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < A.size(); ++i) {
        pq.push(A[i]);
        if(pq.size() > B)
            pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()) {
        ans.emplace_back(pq.top());
        pq.pop();
    }
    return ans;
}
```

```cpp
vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end(), greater<int>());
    return {A.begin(), A.begin()+B};
}
```
