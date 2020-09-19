BFS
```cpp

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
    for(int i = 0; i < B.size(); ++i) {
        adj[B[i][0]].push_back(B[i][1]);
    }
    queue<int> q;
    vector<bool> visited(A+1, false);
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto & v: adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return visited[A];
}
```
DFS
```cpp

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int u) {
    visited[u] = true;
    for(auto & v: adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    visited.clear();
    adj.clear();
    visited.resize(A+1, false);
    adj.resize(A+1);
    for(int i = 0; i < B.size(); ++i) {
        adj[B[i][0]].push_back(B[i][1]);
    }
    dfs(1);
    return visited[A];
}
```
