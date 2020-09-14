```cpp
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    // vector<vector<bool>> user(n, vector<bool> (n, false)); // Memory Limit Exceeded
    set<pair<int,int>> used;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({B.back() + A.back(), {n-1,n-1}});
    // used[n-1][n-1] = true;
    used.insert({n-1,n-1});
    vector<int> ans;
    for(int k = 0; k < n; ++k) {
        auto p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int i = p.second.first;
        int j = p.second.second;
        // if(i > 0 && !used[i-1][j]) {
        if(i > 0 && used.insert({i-1,j}).second) {
            // used[i-1][j] = true;
            pq.push({A[i-1] + B[j], {i-1,j}});
        }
        // if(j > 0 && !used[i][j-1]) {
        if(j > 0 && used.insert({i,j-1}).second) {
            // used[i][j-1] = true;
            pq.push({A[i] + B[j-1], {i, j-1}});
        }
    }
    return ans;
}
```
