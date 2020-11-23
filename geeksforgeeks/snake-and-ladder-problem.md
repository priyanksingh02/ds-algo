# Snake and Ladder Problem
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int t;
    cin >> t;
    unordered_map<int,int> jump;
    while(t--) {
        int a , b;
        cin >> a >> b;
        jump[a] = b;
    }
    int n = 30;
    const int inf = 2000;
    vector<int> dp(n+1, inf);
    dp[1] = 0;
    for(int i = 1; i < 30; ++i) {
        if(jump.count(i)) {
            dp[jump[i]] = min(dp[jump[i]], dp[i]);
        }
        else {
            for(int j = 1; j <= 6 && i + j <= n; ++j) {
                dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
    }
    return dp.back();
}

int main() {
	int t; 
	cin >> t;
	while(t--) {
	    cout << solve() << endl;
	}
}
```
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 30;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; (i+j) <= n && j <= 6; ++j) {
            adj[i].push_back(make_pair(i+j, 1));
        }
    }
    int edges;
    cin >> edges;
    while(edges--) {
        int a, b;
        cin >> a >> b;
        adj[a].clear();
        adj[a].push_back(make_pair(b, 0));
    }
    
    int inf = 1e9;
    vector<int> dist(n+1, inf);
    dist[1] = 0;
    set<pair<int, int>> s;
    s.insert({dist[1], 1});
    while(!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());
        for(auto & v: adj[u]) {
            if(dist[v.first] > dist[u] + v.second) {
                if(dist[v.first] != inf) {
                    s.erase(s.find(make_pair(dist[v.first], v.first)));
                }
                dist[v.first] = dist[u] + v.second;
                s.insert(make_pair(dist[v.first], v.first));
            }
        }
    }
    cout << dist[30] << "\n";
    
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    // q.push(make_pair(0, 1));
    // vector<bool> visited(n+1, false);
    // while(!q.empty()) {
    //     int w = q.top().first;
    //     int u = q.top().second;
    //     q.pop();
    //     if(visited[u])
    //         continue;
    //     visited[u] = true;
    //     if(u == 30) {
    //         cout << w << "\n";
    //         return;
    //     }
    //     for(auto& v: adj[u]) {
    //         q.push(make_pair(w + v.second, v.first));
    //     }
    // }
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

