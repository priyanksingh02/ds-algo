#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m; // n = nodes; m = edges
    cin >> n >> m;
    vector<tuple<int,int, int>> edges;
    for(int i = 0; i < m; ++i) {
        int u, v, w; // u = src; v= dest; w= weight
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u,v,w));
    }
    const int INF = (1<<30);
    vector<int> distance (n + 1, INF);
    distance[1] = 0; // let src be 1;
    for(int i = 1; i <= n -1 ; ++i) {
        for(auto e: edges) {
            int u,v,w;
            tie(u,v,w) = e;
            distance[v] = min(distance[v], distance[u]+w);
        }
    }
    for(unsigned int i = 1; i < distance.size(); i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}
