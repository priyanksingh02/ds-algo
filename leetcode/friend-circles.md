```cpp
class Solution {
public:
    void dfs(vector<vector<int>> & M, int i, vector<bool> & visited) {
        visited[i] = true;
        for(int j= 0; j < M[i].size(); ++j) {
            if(M[i][j] && !visited[j])
                dfs(M, j, visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty() or M.front().empty())
            return 0;
        int m = M.size();
        int n = M.front().size();
        vector<bool> visited(m, false);
        int ans = 0;
        for(int i = 0; i < n; ++i) {a
            if(!visited[i]) {
                ++ans;
                dfs(M, i, visited);
            }
        }
        return ans;
    }
};
```
