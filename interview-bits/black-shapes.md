```cpp

int Solution::black(vector<string> &grid) {
    if(grid.empty() or grid.front().empty())
        return 0;
    int ans = 0;
    int M = grid.size();
    int N = grid[0].size();
    queue<pair<int,int>> q;
    vector<pair<int,int>> direction {{1,0},{0,1},{-1,0},{0,-1}};
    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < M && j < N;  
    };
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(grid[i][j] == 'X') {
                ++ans;
                q.push({i,j});
                grid[i][j] = 'O';
                while(!q.empty()) {
                    auto p = q.front(); q.pop();
                    for(auto & d : direction) {
                        int x = p.first + d.first;
                        int y = p.second + d.second;
                        if(valid(x,y) && grid[x][y] == 'X') {
                            grid[x][y] = 'O';
                            q.push({x,y});
                        }
                    }
                }
            }
        }
    }
    return ans;
}
```
