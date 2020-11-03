# Circle of Strings
```cpp
#include <bits/stdc++.h>
using namespace std;

bool can_connect(string & a, string & b) {
    if(a.empty() or b.empty())
        return false;
    if(a.back() == b.front())
        return true;
    return false;
}

int dfs(int u , int src, int cnt, vector<vector<int>> & g, vector<int> & visited) {
    visited[u] = 1;
    int ans = 0;
    for(int v: g[u]) {
        if(v == src) {
            ans = max(ans, cnt);
        }
        if(!visited[v]) {
            ans = max(ans, dfs(v, src, cnt+1, g, visited));
        }
    }
    return ans;
}   

bool solve() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for(auto & x: strs)
        cin >> x;
    if(n == 1) {
        return can_connect(strs[0],strs[0]);
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(can_connect(strs[i], strs[j]))
                g[i].push_back(j);
        }
    }
    vector<int> visited(n, 0);
    // cycle length should match n
    return dfs(0, 0,1, g, visited) == n;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
```

