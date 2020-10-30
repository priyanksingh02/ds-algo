```cpp

// number of nodes, max till now
pair<int, int> dfs(int u, vector<vector<int>> & adj) {
    if(adj[u].empty()) {
        return {1,0};
    }
    int len1 = 0, len2 = 0;
    int maxtillnow = 0;
    for(int v: adj[u]) {
        auto p = dfs(v, adj);
        if(len1 < p.first) {
            len2 = len1;
            len1 = p.first;
        }
        else if(len2 < p.first) {
            len2 = p.first;
        }
        maxtillnow = max(maxtillnow, p.second);
    }
    return {len1 + 1, max(maxtillnow, len1 + len2)};
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> adj (n);
    int start;
    for(int i = 0; i< n; ++i) {
        if(A[i] == -1) {
            start = i;
        }
        else {
            adj[A[i]].push_back(i);
        }
    }
    auto pr = dfs(start, adj);
    return pr.second;
}
```
