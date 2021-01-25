#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvi = vector<vector<int>>;

auto get_adjlist(vector<tuple<int,int,int>> & edges, int n) -> vvi {
    vvi adj( n, vector<int>(n,0));
    for(auto e: edges) {
        int u, v, w;
        tie(u,v,w) = e;
        adj[u-1][v-1] = w;
        adj[v-1][u-1] = w;
    }
    return adj;
}

int main() {
    int n , m;
    cin>> n>> m;
    vector<tuple<int,int,int>> edges;
    int u,v,w;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u,v,w));
    }
    auto adj = get_adjlist(edges, n);

    const int INF = (1 << 30);
    int distance[n][n];
    // initialize
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j ) {
            if(i ==  j) distance[i][j] = 0;
            else if(adj[i][j]) distance[i][j] = adj[i][j];
            else distance[i][j] = INF;
        }
    }

    //floyd warshall algorithm
    for(int k = 0; k < n; ++k)
        for(int i=0; i < n; ++i)
            for( int j = 0; j < n; ++j) {
                distance[i][j] = min((long long)distance[i][j], (long long)distance[i][k] + distance[k][j]);
            }

    //print distances
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << setw(12) << distance[i][j] ;
        }
        cout << endl;
    }
}
