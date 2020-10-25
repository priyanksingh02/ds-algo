```cpp
vector<pair<int, int>> dijkstra(vector<vector<pair<int,int>>> & adj, int start) {
  using ii = pair<int, int>;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, start});
  vector<bool> visited(adj.size(), false);
  vector<ii> ans;
  while(!pq.empty()) {
    auto pr = pq.top();
    pq.pop();
    int u = pr.second;
    int w = pr.first;
    if(visited[u])
      continue;
    visited[u] = true;
    ans.push_back({u, w});
    for(ii v: adj[u]) {
      pq.push({v.second + w, v.first});
    }
  }
  return ans;
}

```
