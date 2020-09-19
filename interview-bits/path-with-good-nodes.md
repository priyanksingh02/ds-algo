```cpp
int ans;
vector<vector<int>> adj;
vector<bool> visited;
int c;
void dfs(int u, int good, vector<int> & A) {
    visited[u] = true;
    bool leaf = true;
    if(A[u-1])
        ++good;
    for(auto & v: adj[u]) {
        if(!visited[v]) {
            leaf = false;
            dfs(v, good, A);
        }
    }
    if(leaf && good <= c) {
        ++ans;
    }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    ans = 0;
    c = C;
    int n = A.size();
    adj.clear();
    visited.clear();
    adj.resize(n+1);
    visited.resize(n+1, false);
    for(int i = 0; i < B.size(); ++i) {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    dfs(1, 0, A);
    return ans;
}
```
