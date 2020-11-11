#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>> & adj, int src) {
  int V = adj.size();
  const int inf= 1e9 + 7;
  vector<int> dist (V, inf);
  dist[src] = 0;
  set<pair<int,int>> s;
  s.insert({dist[src], src});
  while(!s.empty()) {
    int u = s.begin()->second;
    s.erase(s.begin());
    for(auto & v: adj[u]) {
      if(dist[v.first] > dist[u] + v.second) {
        if(dist[v.first] != inf) {
          s.erase(s.find({dist[v.first], v.first}));
        }
        dist[v.first] = dist[u] + v.second;
        s.insert({dist[v.first], v.first});
      }
    }
  }
  return dist;
}

int main() {
  //Input
  int V = 10;
  vector<vector<int>> edges {
    {1, 4, 5}, {3, 2, 7}, {1, 2, 1}, {1, 3, 2}, {2, 4, 6}, {2, 4, 2}, 
    {4, 5, 6}, {3, 5, 3}, {3, 6, 5}, {4, 7, 3},  {4, 9, 1}, {5, 10, 3}, 
    {5, 6, 2}, {1, 8, 7},{4, 8, 2}
  };
  // Prep
  vector<vector<pair<int,int>>> adj(V+1);
  for(auto & e: edges) {
    adj[e[0]].push_back({e[1], e[2]});
    adj[e[1]].push_back({e[0], e[2]});
  }
  // Call
  int node = 0;
  for(int d: dijkstra(adj, 1)) {
    cout << node++ << " : " << d << endl;
  }
}
