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
