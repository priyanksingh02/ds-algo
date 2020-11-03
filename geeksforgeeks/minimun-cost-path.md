# Minimum Cost Path

NOTE: Priority queue implementation of dijkstra gave TLE.
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n = 0;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j =0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    vector<pair<int, int>> direction {{-1,0},{1,0},{0,1},{0,-1}};
    auto valid = [&](int i , int j) {
        return i >= 0 && j >= 0 && i < n && j < n;  
    };
    dist[0][0] = g[0][0];
    set<tuple<int,int,int>> s;
    s.insert(make_tuple(dist[0][0], 0, 0));
    while(!s.empty()) {
        int u, v, w;
        tie(w, u, v) = *s.begin();
        if(u + 1== n && v + 1 == n)
            return dist[n-1][n-1];
        s.erase(s.begin());
        for(auto &d : direction) {
            int i = u + d.first;
            int j = v + d.second;
            if(valid(i,j) && dist[i][j] > dist[u][v] + g[i][j]) {
                if(dist[i][j] != INT_MAX)
                    s.erase(s.find(make_tuple(dist[i][j], i, j)));
                dist[i][j] = dist[u][v] + g[i][j];
                s.insert(make_tuple(dist[i][j], i, j));
            }
        }
    }
    return dist[n-1][n-1];
}

int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
```

