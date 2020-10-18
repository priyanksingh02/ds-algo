```cpp

int row[9];
int col[9];
int box[3][3];
int N;
void mark(int &x, int pos) {
    x |= (1 << pos);
}
void clear(int &x, int pos) {
    x &= ~(1 << pos);
}

void markall(int i, int j, int n) {
    mark(row[i], n);
    mark(col[j], n);
    mark(box[i/3][j/3], n);
}

void clearall(int i, int j, int n) {
    clear(row[i], n);
    clear(col[j], n);
    clear(box[i/3][j/3], n);
}

bool query(int x, int pos) {
    return x & (1 << pos);
}

bool taken(int i, int j, int n) {
    return query(row[i], n) or query(col[j], n) or query(box[i/3][j/3], n);
}

pair<int,int> nextpos(pair<int,int> a) {
    a.second++;
    if(a.second == N) {
        a.second = 0;
        a.first ++;
    }
    return a;
}

bool solve(vector<vector<char>> & A, pair<int,int> pos) {
    int i = pos.first;
    int j = pos.second;
    if(i == N)
        return true;
    if(A[i][j] == '.') {
        for(int k = 1; k <= 9; ++k) {
            if(!taken(i,j,k)) {
                markall(i,j,k);
                A[i][j] = '0' + k;
                if(solve(A, nextpos({i,j}))) {
                    return true;
                }
                A[i][j] = '.';
                clearall(i,j,k);
            }
        }
    }
    else {
        if(solve(A, nextpos({i,j})))
            return true;
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(box, 0, sizeof(box));
    N = A.size();
    for(int i = 0; i< N; ++i) {
        for(int j = 0; j <N; ++j) {
            if(A[i][j] != '.') {
                markall(i,j, A[i][j] - '0');
            }
        }
    }
    solve(A,{0,0});
}
```
