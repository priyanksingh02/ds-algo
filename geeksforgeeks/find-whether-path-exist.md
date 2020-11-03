```cpp
#include <bits/stdc++.h>
using namespace std;

static const vector<pair<int,int>> direction {{-1, 0}, {1,0}, {0,-1},{0,1}};

bool dfs(int i, int j, vector<vector<int>> & g) {
    if(i < 0 or j < 0 or i >= g.size() or j >= g[0].size() or g[i][j] == 0)
        return false;
    if(g[i][j] == 2)
        return true;
    g[i][j] = 0;
    for(auto & d: direction) {
        if(dfs(i+d.first, j+d.second, g))
            return true;
    }
    return false;
}

bool solve() {
    int n;
    cin >> n;
    if(n == 0)
        return false;
    int x, y;
    vector<vector<int>> g (n, vector<int> (n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> g[i][j];
            if(g[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }
   if(dfs(x, y, g))
        return true;
    return false;
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
