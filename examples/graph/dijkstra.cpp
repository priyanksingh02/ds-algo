#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

auto get_adjlist(vector<tuple<int,int,int>> & edges, int nodes) -> vector<vector<pair<int,int>>>
{
    vector<vector<pair<int,int>>> adj (nodes);
    int u,v,w;
    for(auto e: edges) {
        tie(u,v,w) = e;
        adj[u-1].push_back(make_pair(v-1,w));
        adj[v-1].push_back(make_pair(u-1,w));
    }
    return adj;
}

auto dijkstra(vector<vector<pair<int,int>>> & adj, int src) -> vector<int>
{
    const int INF = (1 << 30);
    vector<int> distance (adj.size(), INF);
    distance[src] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,src));
    vector<bool> visited (adj.size(), false);
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto node: adj[u]) {
            int v = node.first;
            int w = node.second;
            if(distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push(make_pair(-distance[v],v));
            }
        }
    }
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    int u, v, w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u,v,w));
    }
    auto adj = get_adjlist(edges,n);

    auto distances = dijkstra(adj, 0);
    // answer: 0 5 7 3 1
    for(auto d: distances) {
        cout << d << " ";
    }
    cout << endl;
}
