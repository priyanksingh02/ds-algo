# Two Teams
```cpp
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> visited(A+1, 0);
    vector<vector<int>> adj(A+1);
    for(auto & v: B) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    //bfs
    for(int i = 1; i <= A; ++i) {
        if(!visited[i]) {
            queue<pair<int, bool>> q;
            q.push({i, false});
            while(!q.empty()) {
                auto p = q.front(); q.pop();
                int val = 1 + (int)p.second;
                for(int v: adj[p.first]) {
                    if(!visited[v]) {
                        visited[v] = (val == 1)?2:1;
                        q.push({v, true^p.second});
                    }
                    else {
                        if(visited[v] == val)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

```

