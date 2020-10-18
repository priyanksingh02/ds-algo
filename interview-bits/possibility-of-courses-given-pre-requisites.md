```cpp


bool dfs(int u, vector<vector<int>> & adj, vector<int> & visited) {
    visited[u] = 1;
    for(auto & v: adj[u]) {
        if(visited[v] == 1) {
            return false;
        }   
        if(!visited[v]) {
            if(!dfs(v, adj, visited))
                return false;
        }
    }
    visited[u] = 2;
    return true;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> adj(A+1);
    for(int i = 0; i < B.size(); ++i) {
        adj[B[i]].push_back(C[i]);
    }
    vector<int> visited(A+1, 0);
    for(int i = 1; i <= A; ++i) {
        if(!visited[i]) {
            if(!dfs(i,adj, visited))
                return false;
        }
    }
    return true;
}
```
