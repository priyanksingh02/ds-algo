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
