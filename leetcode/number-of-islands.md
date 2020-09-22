```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() or grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        auto valid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < m && j < n;  
        };
        vector<pair<int,int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};
        int ans = 0;
        for(int i = 0; i< m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    ++ans;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
                    while(!q.empty()) {
                        auto p = q.front(); q.pop();
                        for(auto d: direction) {
                            int ii = p.first + d.first;
                            int jj = p.second + d.second;
                            if(valid(ii,jj) && grid[ii][jj] =='1') {
                                grid[ii][jj] = '0';
                                q.push({ii,jj});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```
