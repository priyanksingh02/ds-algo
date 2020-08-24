```cpp
const vector<pair<int,int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};
class Solution {
    vector<vector<int>> visited;
    int R, C;
    char cur_char;
    bool found;
public:
    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < R && j < C;
    }
    void dfs(vector<vector<char>> & grid, int i, int j , int previ, int prevj) {
        visited[i][j] = 1;
        for(auto & d: direction) {
            int ii = i + d.first;
            int jj = j + d.second;
            if(valid(ii,jj) && (ii != previ || jj != prevj) && visited[ii][jj] == 1) {
                found = true;
                break;
            }
            if(!found && valid(ii,jj) && visited[ii][jj] == 0 && grid[ii][jj] == cur_char) {
                dfs(grid, ii, jj, i, j);
            }
        }
        visited[i][j] = 2;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        found = false;
        R = grid.size();
        C = grid.front().size();
        visited.resize(R, vector<int> (C, 0));
        for(int i = 0; i < R && !found; ++i) {
            for(int j = 0; j < C && !found; ++j) {
                if(visited[i][j] == 0) {
                    cur_char = grid[i][j];
                    dfs(grid, i, j, -1, -1);
                }
            }
        }
        return found;
    }
};
```
