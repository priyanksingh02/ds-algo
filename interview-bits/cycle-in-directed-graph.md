```cpp
bool dfs(int u, const vector<vector<int>> & adj, vector<int> & visited) {
    visited[u] = 1;
    for(auto & v: adj[u]) {
        if(visited[v] == 1)
            return true;
        if(!visited[v]) {
            if(dfs(v, adj, visited))
                return true;
        }
    }
    visited[u] = 2;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {

    vector<vector<int>> adj(A+1);
    for(auto & e: B) {
        adj[e[0]].push_back(e[1]);
    }
    vector<int> visited(A+1, 0);
    for(int i = 1; i <= A; ++i) {
        if(visited[i] == 0) {
            if(dfs(i, adj, visited))
                return true;
        }
    }
    return false;
}
```
