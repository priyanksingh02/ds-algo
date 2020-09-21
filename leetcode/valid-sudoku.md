```cpp
class Solution {
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, box[3][3] = {0};
        auto insert = [](int & place, int num) {
            place |= 1 << num;
        };
        auto query = [](int place, int num) {
            return place & (1 << num);
        };
        auto mark = [&](int i, int j, int num) {
            insert(col[j], num);
            insert(row[i], num);
            insert(box[i/3][j/3], num);
        };
        auto taken = [&](int i, int j, int num) {
            return query(col[j], num) || query(row[i], num) || query(box[i/3][j/3], num);
        };
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if(!taken(i,j,num))
                        mark(i,j,num);
                    else 
                        return false;
                }
            }
        }
        return true;
    }
};
```
