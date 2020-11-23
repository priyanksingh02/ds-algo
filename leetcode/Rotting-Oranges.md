BFS - O(n)
```cpp
class Solution { // O(n) BFS
  public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int orangesRotting(vector<vector<int>>& grid) {
      if(grid.empty()) return 0;
      int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
      queue<pair<int, int>> rotten;
      for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
          if(grid[i][j] != 0) tot++;
          if(grid[i][j] == 2) rotten.push({i, j});
        }
      }

      while(!rotten.empty()){
        int k = rotten.size();
        cnt += k; 
        while(k--){
          int x = rotten.front().first, y = rotten.front().second;
          rotten.pop();
          for(int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
            grid[nx][ny] = 2;
            rotten.push({nx, ny});
          }
        }
        if(!rotten.empty()) days++;
      }

      return tot == cnt ? days : -1;
    }
};
```
DFS
```cpp
class Solution {
  vector<pair<int, int>> direction {{0,1},{1, 0},{-1,0},{0,-1}};
  public:
  void dfs(int i, int j, int l, vector<vector<int>> & grid) {
    if(i < 0 or j < 0 or i == grid.size() or j == grid[0].size() or grid[i][j] == 2 or grid[i][j] == 0)
      return;
    if(grid[i][j] != 1 && grid[i][j] >= l)
      return;
    grid[i][j] = l;
    for(auto & d: direction) {
      dfs(i + d.first, j + d.second, l-1, grid);
    }
  }

  int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty() or grid[0].empty())
      return 0;
    int M = grid.size();
    int N = grid[0].size();
    for(int i = 0; i < M; ++i) {
      for(int j = 0; j < N; ++j) {
        if(grid[i][j] == 2) {
          grid[i][j] = 1;
          dfs(i, j, 0, grid);
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < M; ++i) {
      for(int j = 0; j < N; ++j) {
        if(grid[i][j] < 0)
          ans = min(ans, grid[i][j]);
        if(grid[i][j] == 1)
          return -1;
      }
    }
    return abs(ans);
  }
};
```
```cpp
class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
      vector<pair<int,int>> direction { { 0,1}, {1,0}, {-1,0}, {0,-1}};
      if(grid.empty() || grid.front().empty())
        return 0;
      int R = grid.size();
      int C = grid.front().size();
      auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < R && j < C;  
      };

      for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
          if(grid[i][j] == 2) {
            queue<tuple<int,int,int>> q;
            q.push(make_tuple(i,j,0));
            while(!q.empty()) {

              auto pr = q.front(); q.pop();
              int r, c, t;
              tie(r,c,t) = pr;
              c = pr.second.second;
              for(auto &d : direction) {
                int ri = r + d.first;
                int cj = c + d.second;

                if(valid(ri,cj) && grid[ri][cj] <= 1 && grid[ri][cj] != 0 ) {
                  if(grid[ri][cj] == 1 or abs(grid[ri][cj]) > abs(t - 1)) {
                    grid[ri][cj] = t-1;
                    q.push(make_tuple(ri,cj,grid[ri][cj]));
                  }
                }
              }
            }
          }   
        }
      }
      int ans = 0;
      for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
          if(grid[i][j] == 1)
            return -1;
          if(grid[i][j] < 0)
            ans = max(ans, abs(grid[i][j]));
        }
      }
      if(ans == INT_MAX)
        return 0;
      return ans;
    }
};
```
