```cpp
vector<bool> col;
vector<bool> pdiag;
vector<bool> adiag;
int n;

bool taken(int i, int j) {
    return col[j] || pdiag[j - i + n] || adiag[i+j];
}

void mark(int i, int j) {
    col[j] = true;
    pdiag[j-i +n] = true;
    adiag[i+j] = true;
}

void clear(int i, int j) {
    col[j] = false;
    pdiag[j-i+n] = false;
    adiag[i+j] = false;
}

void solve(vector<string> & grid, int r, vector<vector<string>> & ans) {
    if(r == n) {
        ans.push_back(grid);
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!taken(r,i)) {
            mark(r,i);
            grid[r][i] = 'Q';
            solve(grid, r+1, ans);
            clear(r,i);
            grid[r][i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    n = A;
    col.clear();
    pdiag.clear();
    adiag.clear();
    col.resize(n, false);
    pdiag.resize(2*n, false);
    adiag.resize(2*n, false);
    vector<vector<string>> ans;
    vector<string> grid (n, string(n,'.'));
    solve(grid, 0, ans);
    return ans;
    
}

```
```cpp

int sz;
vector<bool> row;
vector<bool> col;
vector<bool> pdiagonal;
vector<bool> adiagonal;
vector<vector<string>> ans;

void mark(int i, int j) {
    row[i] = true;
    col[j] = true;
    pdiagonal[(j - i) + sz] = true;
    adiagonal[i+j] = true;
}

void clear(int i, int j) {
    row[i] = false;
    col[j] = false;
    pdiagonal[(j - i) + sz] = false;
    adiagonal[i+j] = false;
}

bool taken(int i, int j) {
    return row[i] || col[j] || pdiagonal[(j-i) + sz] || adiagonal[i+j];  
}

// for every row r, try to fill 1 queen
void solve(vector<string> & puzzle, int r) {
    if(r == sz) {
        ans.push_back(puzzle);
        return;
    }
    for(int i = 0; i < sz; ++i) {
        if(!taken(r,i)) {
            puzzle[r][i] = 'Q';
            mark(r,i);
            solve(puzzle, r+1);
            clear(r,i);
            puzzle[r][i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int sz) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ::sz = sz;
    ans.clear();
    vector<string> puzzle(sz, string(sz,'.') );
    row.resize(sz, false);
    col.resize(sz, false);
    pdiagonal.resize(2*sz + 1, false);
    adiagonal.resize(2*sz + 1, false);
    solve(puzzle, 0);
    return ans;
}
```

```cpp

int sz;
vector<bool> row;
vector<bool> col;
vector<bool> pdiagonal;
vector<bool> adiagonal;
vector<vector<string>> ans;
int num = 0;

void mark(int i, int j) {
    row[i] = true;
    col[j] = true;
    pdiagonal[(j - i) + sz] = true;
    adiagonal[i+j] = true;
}

void clear(int i, int j) {
    row[i] = false;
    col[j] = false;
    pdiagonal[(j - i) + sz] = false;
    adiagonal[i+j] = false;
}

bool taken(int i, int j) {
    return row[i] || col[j] || pdiagonal[(j-i) + sz] || adiagonal[i+j];  
}

void fill(vector<string> & puzzle, int i, int j) {
    if(j == sz) {
        j = 0;
        i++;
    }
    if(i == sz) {
        return;
    }
    
    if(!taken(i,j)) {
        puzzle[i][j] = 'Q';
        ++num;
        if(num == sz) {
            ans.push_back(puzzle);
        }
        else {
            mark(i,j);
            fill(puzzle,i, j+1);
        }
        puzzle[i][j] = '.';
        clear(i,j);
        --num;
    }
    fill(puzzle,i,j+1);
}

vector<vector<string> > Solution::solveNQueens(int sz) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ::sz = sz;
    num = 0;
    ans.clear();
    vector<string> puzzle(sz, string(sz,'.') );
    row.resize(sz, false);
    col.resize(sz, false);
    pdiagonal.resize(2*sz + 1, false);
    adiagonal.resize(2*sz + 1, false);
    fill(puzzle, 0, 0);
    return ans;
}
```
