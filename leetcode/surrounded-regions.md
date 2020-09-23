```cpp
class Solution {
    int m;
    int n;
    vector<pair<int,int>> direction {{-1,0},{0,-1},{0,1},{1,0}};
public:
    void dfs(vector<vector<char>> & board, int i, int j) {
        if(i < 0 or j < 0 or j>= n or i>= m or board[i][j] != 'O')
            return;
        board[i][j] = 'L';
        for(auto & d: direction) {
            dfs(board, i+d.first, j+d.second);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() or board[0].empty())
            return ;
        m = board.size();
        n = board[0].size();
        for(int i= 0; i < m; ++i) {
            if(board[i][0] == 'O')
                dfs(board,i,0);
            if(board[i][n-1] == 'O')
                dfs(board,i,n-1);
        }
        for(int i = 0; i < n; ++i) {
            if(board[0][i] == 'O')
                dfs(board,0,i);
            if(board[m-1][i] == 'O')
                dfs(board,m-1,i);
        }
        for(int i = 0; i< m; ++i) {
            for(int j = 0; j<n; ++j) {
                if(board[i][j] == 'L')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
```
