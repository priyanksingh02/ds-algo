# Floyd Warshall - All pair shortest path using Adjacency Matrix
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    const int inf = 1e7;
    vector<vector<int>> g(n,  vector<int> (n, 0));
    string in;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> in;
            if(in[0] == 'I')
                g[i][j] = inf;
            else
                g[i][j] = stoi(in);
        }
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0;j  < n; ++j) {
                if(g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(g[i][j] >= inf)
                cout << "INF ";
            else
                cout << g[i][j] << ' ';
        }
        cout << "\n";
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
```

