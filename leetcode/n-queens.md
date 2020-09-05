```cpp
class Solution {
    vector<vector<string>> ans;
    int total;
    vector<bool> col, pdiag, auxdiag;
public:
    void mark(int i, int j) {
        col[j] = true;
        pdiag[j-i+total] = true;
        auxdiag[i+j] = true;
    }
    
    void clear(int i, int j) {
        col[j] = false;
        pdiag[j-i+total] = false;
        auxdiag[i+j] = false;
    }
    
    bool under_attack(int i, int j) {
        return col[j] || pdiag[j-i+total] || auxdiag[i+j];
    }
    
    void solve(int r, vector<string> & board) {
        if(r == total) {
            ans.push_back(board);
        }
        else {
            for(int i = 0; i < total; ++i) {
                if(!under_attack(r,i)) {
                    board[r][i] = 'Q';
                    mark(r,i);
                    solve(r+1, board);
                    board[r][i] = '.';
                    clear(r,i);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        total = n;
        col.resize(n, false);
        pdiag.resize(2*total, false);
        auxdiag.resize(2*total, false);
        vector<string> board(n, string(n,'.'));
        solve(0, board);
        return ans;
    }
};
```

## n-queens II
```cpp
class Solution {
    int ans;
    vector<int> col, pdiag, auxdiag;
public:
    void mark(int i, int j, int n) {
        col[j] = true;
        pdiag[j-i+n] = true;
        auxdiag[i+j] = true;
    }
    void clear(int i , int j , int n) {
        col[j] = false;
        pdiag[j-i+n] = false;
        auxdiag[i+j] = false;
    }
    bool under_attack(int i, int j, int n) {
        return col[j] || pdiag[j-i+n] || auxdiag[i+j];
    }
    void solve(int r, int n) {
        if(r == n) {
            ans += 1;
        }
        else {
            for(int i = 0; i < n; ++i) {
                if(!under_attack(r,i,n)) {
                    mark(r,i,n);
                    solve(r+1, n);
                    clear(r,i,n);
                }
            }
        }
    }
    
    int totalNQueens(int n) {
        col.resize(n, false);
        pdiag.resize(2*n, false);
        auxdiag.resize(2*n, false);
        ans = 0;
        solve(0,n);
        return ans;
    }
};

```
