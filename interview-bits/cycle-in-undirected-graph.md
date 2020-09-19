```cpp
vector<vector<int>> adj;
vector<bool> visited;
bool cycle;

void dfs(int u, int prev) {
    visited[u] = true;
    for(auto & v: adj[u]) {
        if(visited[v] && v != prev)
            cycle = true;
        if(!visited[v] and !cycle) {
            dfs(v, u);
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    cycle = false;
    adj.clear();
    visited.clear();
    adj.resize(A+1);
    visited.resize(A+1, false);
    for(int i = 0; i< B.size(); ++i) {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    for(int i = 1; i <= A; ++i) {
        if(!visited[i])
            dfs(i,0);
    }
    return cycle;
}
```
