```cpp
vector<pair<int, int>> dijkstra(vector<vector<pair<int,int>>> & adj, int start) {
  int n = adj.size();
  const int inf = 1e9;
  vector<int> dist(n, inf);
  dist[start] = 0; // STEP 1
  set<pair<int,int>> s;
  s.insert(make_pair(dist[start], start)); // STEP 2
  while(!s.empty()) {
    int u = s.begin()->second; s.erase(s.begin()); // STEP 3
    for(auto & v: adj[u]) {
      if(dist[v.first] > dist[u] + v.second) { // STEP 4
        if(dist[v.first] != inf) // very important!
          s.erase(s.find(make_pair(dist[v.first], v.first)));
        dist[v.first] = dist[u] + v.second;
        s.insert(make_pair(dist[v.first], v.first));
      }
    }
  }
  // not necessary
  vector<pair<int,int>> ans;
  for(int i = 0; i < n; ++i) {
    ans.push_back({i, dist[i]});
  }
  return ans;
}
```

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
