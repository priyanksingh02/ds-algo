Idea: Return all nodes with indegree 0
```cpp
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        for(auto & e: edges) {
            visited[e[1]] = true;
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            if(!visited[i])
                ans.push_back(i);
        }
        return ans;
    }
};
```

```cpp
class Solution {
    set<int> ans;
    vector<bool> visited;
    vector<vector<int>> adjlist ;
public:
    void dfs(int i) {
        visited[i] = true;
        for(auto & v: adjlist[i]) {
            auto it = ans.find(v);
            if(it != ans.end())
                ans.erase(it);
            if(!visited[v]) {
                dfs(v);
            }
        }
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        adjlist.resize(n);
        for(auto &e : edges) {
            adjlist[e[0]].push_back(e[1]);
        }
        visited.resize(n, false);
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                ans.insert(i);
                dfs(i);
            }
        }
        return {ans.begin(), ans.end()};
    }
};
```
