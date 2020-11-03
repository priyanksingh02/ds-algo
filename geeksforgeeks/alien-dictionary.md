# Alien Dictionary (Topological Sort)
```cpp
/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/
void dfs(int u, vector<vector<int>> & g, vector<bool> & visited, vector<int> & ans) {
    visited[u] = true;
    for(int v: g[u]) {
        if(!visited[v])
            dfs(v, g, visited, ans);
    }
    ans.push_back(u);
}

string findOrder(string dict[], int N, int K) {
    vector<vector<int>> g(K);
    // Generate graph using first mismatch
    for(int i = 1; i < N; ++i) {
        int limit = min(dict[i].size(), dict[i-1].size());
        for(int j = 0; j < limit; ++j) {
            if(dict[i][j] != dict[i-1][j]) {
                g[dict[i-1][j] - 'a'].push_back(dict[i][j] - 'a');
                break; // only consider first mismatch
            }
        }
    }
    // Topological sort -> answer
    vector<int> ans;
    vector<bool> visited(K, false);
    for(int i = 0; i < K; ++i) {
        if(!visited[i]) {
            dfs(i, g, visited, ans);
        }
    }
    string order;
    for(int i = (int)ans.size() -1 ; i >= 0; --i) {
        order.push_back(ans[i]+'a');
    }
    return order;
}
```

