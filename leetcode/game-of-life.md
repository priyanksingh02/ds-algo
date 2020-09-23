IN PLACE
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() or board[0].empty())
            return ;
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> direction {{-1,-1},{-1,0},{-1,1},
                                         {0,-1},{0,1},
                                         {1,-1},{1,0},{1,1}};
        auto valid = [&](int i, int j) {
            return i >= 0 && j >= 0 && i < m && j < n;
        };
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int count = 0;
                for(auto d: direction) {
                    if(valid(i+d.first,j+d.second) && 
                       (board[i+d.first][j+d.second] & 1))
                        ++count;
                }
                if(count == 3 || (count == 2 && (board[i][j] & 1)))
                    board[i][j] |= 2; // use second bit to store ans
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j= 0; j < n; ++j) {
                board[i][j] >>=1;
            }
        }
    }
};
```
Extra space
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() or board[0].empty())
            return ;
        vector<vector<int>> ans {board};
        vector<pair<int,int>> direction {{-1,-1},{-1,0},{-1,1},
                                         {0,-1},{0,1},
                                         {1,-1},{1,0},{1,1}};
        auto valid = [&](int i, int j) {
            return i >= 0 and j >= 0 and i < board.size() and j < board[0].size();  
        };
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                int count = 0;
                for(auto d: direction) {
                    int ii =  i+d.first;
                    int jj = j + d.second;
                    if(valid(ii,jj) && board[ii][jj])
                        ++count;
                }
                if((board[i][j] && (count == 2 || count == 3))
                   || (!board[i][j] && count == 3))
                    ans[i][j] = 1;
                else 
                    ans[i][j] = 0;
                
            }
        }
        board = ans;
    }
};
```
