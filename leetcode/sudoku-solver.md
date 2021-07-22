```cpp
class Solution {
    int row[9];
    int col[9];
    int box[3][3];
    
    void fill(int & x, int num) {
        x |= 1UL << num;
    }
    
    bool check(int x, int num) {
        return x & (1UL << num);
    }
    
    void remove(int & x, int num) {
        x &= ~(1UL<<num);
    }
    
public:
    
    Solution() {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
    }
    
    void mark(int i, int j, int num) {
        fill(row[i], num);
        fill(col[j], num);
        fill(box[i/3][j/3], num);
    }
    
    void clear(int i, int j, int num) {
        remove(row[i], num);
        remove(col[j], num);
        remove(box[i/3][j/3], num);
    }
    
    bool taken(int i, int j, int num) {
        return check(row[i], num) or check(col[j], num) or check(box[i/3][j/3], num);
    }
    
    pair<int, int> next_pos(pair<int,int> pos) {
        if(pos.second == 8) {
            pos.first++;
            pos.second = 0;
        }
        else {
            pos.second++;
        }
        return pos;
    }
    
    bool solve(vector<vector<char>> & board, pair<int,int> pos) {
        if(pos.first == board.size())
            return true; // solved
        int i = pos.first;
        int j = pos.second;
        if(board[i][j] == '.') {
            for(int k = 1; k <= 9; ++k) {
                if(!taken(i, j, k)) {
                    mark(i, j, k);
                    board[i][j] = k + '0';
                    if(solve(board, next_pos(pos))) {
                        return true;
                    }
                    clear(i,j,k);
                    board[i][j] = '.';
                }
            }
        }
        else {
            return solve(board, next_pos(pos));
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int sz = board.size();
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j < sz; ++j) {
                if(board[i][j] != '.') {
                    mark(i, j, board[i][j]-'0');
                }
            }
        }
        
        cout << "result = " << solve(board, {0, 0}) << endl;
    }
};
```
