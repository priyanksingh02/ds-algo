```cpp
// Topological Sort
class Solution {
  public:

    bool dfs(int u, vector<vector<int>> & adj, vector<int> & visited, string& ans) {
      visited[u] = 1;
      for(int & v: adj[u]) {
        if(visited[v] == 1) {
          return true;
        }
        if(!visited[v]) {
          if(dfs(v, adj, visited, ans))
            return true;
        }
      }
      visited[u] = 2;
      ans.push_back(u+'a');
      return false;
    }

    string alienOrder(vector<string>& words) {
      if(words.empty()) return "";
      int n = 26;
      vector<bool> seen(n);
      for(auto & s: words) {
        for(auto &c: s) {
          seen[c-'a'] = true;
        }
      }
      vector<vector<int>> adj(n);
      for(int i = 1; i < words.size(); ++i) {
        bool invalid = true;
        for(int j = 0; j < words[i-1].size() && j < words[i].size(); ++j) {
          if(words[i-1][j] != words[i][j]) {
            adj[words[i-1][j]-'a'].push_back(words[i][j]-'a');
            invalid = false;
            break;
          }
        }
        if(invalid && words[i-1].size() > words[i].size())
          return "";
      }
      string ans;
      vector<int> visited(n, 0);
      for(int i = 0; i < n; ++i) {
        if(!visited[i] and seen[i]) {
          if(dfs(i, adj, visited, ans))
            return "";
        }
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};

```
