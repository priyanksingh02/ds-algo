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
