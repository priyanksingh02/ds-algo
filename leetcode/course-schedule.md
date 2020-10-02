## Course Schedule
```cpp
class Solution {
public:
    bool detect_cycle(vector<vector<int>> & adj, int u, vector<int> & visited) {
        visited[u] = 1;
        for(auto & v: adj[u]) {
            if(visited[v] == 1)
                return true;
            if(!visited[v]) {
                if(detect_cycle(adj, v, visited))
                    return true;
            }
        }
        visited[u] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto & edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited (numCourses, 0);
        bool found = false;
        for(int i = 0; i < numCourses && !found; ++i) {
            if(!visited[i]) {
                found = detect_cycle(adj, i, visited);
            }
        }
        return !found;
    }
};
```
## Course Schedule II
```cpp
class Solution {
public:
    bool dfs(vector<vector<int>> & adj, int u, vector<int>& visited, vector<int>&ans) {
        visited[u] = 1;
        for(auto & v: adj[u]) {
            if(visited[v] == 1)
                return false;
            if(!visited[v]) {
                if(!dfs(adj, v, visited, ans))
                    return false;
            }
        }
        visited[u] = 2;
        ans.push_back(u);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        for(auto & edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> ans;
        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i]) {
                if(!dfs(adj, i, visited, ans))
                    return {}; // in case of cycle
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
