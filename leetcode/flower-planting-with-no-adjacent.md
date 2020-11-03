## Graph colouring approach
```cpp
class Solution {
public:
  bool fill(int cur, vector<int> & ans, vector<vector<int>> & g) {
    if(cur >= ans.size())
       return true;
    vector<bool> available(5, true);
    available[0] = false;
    for(int v: g[cur]) {
      available[ans[v]] = false;
    }
    for(int i = 0; i < 5; ++i) {
      if(available[i]) {
        ans[cur] = i;
        if(fill(cur+1, ans, g)) {
          return true;
        }
        ans[cur] = 0;
      }
    }
    return false;
  }
  
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<int> ans(n+1, 0);
    vector<vector<int>> g(n+1);
    for(auto& v: paths) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }
    fill(1, ans, g);
    ans.erase(ans.begin());
    return ans;
  }
};
```
