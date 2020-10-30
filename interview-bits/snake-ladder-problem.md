```cpp

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n  = 101;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= 6 && i+j < n; ++j) {
            adj[i].push_back({i+j, 1});
        }
    }
    for(int i = 0; i < A.size(); ++i) {
        adj[A[i][0]].clear();
        adj[A[i][0]].push_back({A[i][1], 0});
    }
    for(int i = 0; i < B.size(); ++i) {
        adj[B[i][0]].clear();
        adj[B[i][0]].push_back({B[i][1], 0});
    }
    using ii = pair<int,int>;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 1});
    vector<bool> visited (n, false);
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int cost = p.first;
        int u = p.second;
        if(u == 100) {
            return cost;
        }
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto & v: adj[u]) {
            pq.push({v.second+cost, v.first});
        }
    }
    return -1;
}
```
