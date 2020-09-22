```cpp
class Solution {
    vector<pair<int,int>> direction {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<bool>> visited;
public:
    bool dfs(vector<vector<char>> & board, int i, int j, string & word, int pos) {
        if(pos == word.size())
            return true;
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size())
            return false;
        if(visited[i][j] || board[i][j] != word[pos])
            return false;
        visited[i][j] = true;
        for(auto & d: direction) {
            if(dfs(board, i+d.first, j+d.second, word, pos+1))
                return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == word[0]) {
                    visited.clear();
                    visited.resize(m, vector<bool>(n, false));
                    if(dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
```
