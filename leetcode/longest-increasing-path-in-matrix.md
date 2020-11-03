Idea: Start with the sinks, build a path in backward direction
```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() or matrix[0].empty())
            return 0;
        vector<pair<int,int>> idx;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i =0; i < m; ++i) {
            for(int j = 0;j < n; ++j) {
                idx.push_back(make_pair(i,j));
            }
        }
        sort(idx.begin(), idx.end(), [&](pair<int,int> & a, pair<int,int> & b){
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        });
        
        vector<vector<int>> grid(m, vector<int> (n, 1));
        int maxlen = 0;
        auto valid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < m && j < n;
        };
        vector<pair<int,int>> direction{{-1,0},{0,-1},{0,1},{1,0}};
        for(auto & pr: idx) {
            for(auto & d: direction) {
                int i = pr.first + d.first;
                int j = pr.second + d.second;
                if(valid(i,j) && matrix[i][j] > matrix[pr.first][pr.second]) {
                    grid[pr.first][pr.second] = max(grid[i][j] + 1, grid[pr.first][pr.second]);
                }
            }
            maxlen = max(maxlen, grid[pr.first][pr.second]);
        }
        return maxlen;
    }
};
   
```
```cpp

class Solution {
    vector<pair<int,int>> direction {{-1,0},{0,-1},{0,1},{1,0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() or matrix.front().empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxlen = 0;
        vector<vector<int>> ans(m, vector<int> (n, -1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(ans[i][j] == -1) {
                    dfs(ans, matrix,i,j);
                    maxlen = max(maxlen, ans[i][j]);
                }
            }
        }
        return maxlen;
    }

    void dfs(vector<vector<int>> & ans, vector<vector<int>> & matrix, int i, int j ) {
        int count = 1;
        for(auto d: direction) {
            int ii = i + d.first;
            int jj = j + d.second;
            if(valid(ans,ii,jj) && matrix[ii][jj] > matrix[i][j]) {
                if(ans[ii][jj] == -1) {
                    dfs(ans, matrix, ii, jj);
                }
                count = max(count, 1+ans[ii][jj]);
            }
        }
        ans[i][j] = count;

    }

    bool valid(vector<vector<int>> & ans, int i, int j) {
        return i >= 0 && j >= 0 && i < ans.size() && j < ans[0].size();
    }
};
```
