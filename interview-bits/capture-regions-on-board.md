```cpp
void dfs(int i, int j, vector<vector<char>> & grid) {
    if(i < 0 or j < 0 or i == grid.size() or j == grid[i].size() or grid[i][j] != 'O')
        return;
    grid[i][j] = 'M';
    dfs(i-1,j, grid);
    dfs(i+1,j, grid);
    dfs(i, j-1, grid);
    dfs(i, j+1, grid);
}

void Solution::solve(vector<vector<char> > &A) {
    if(A.empty() or A[0].empty())
        return ;
    int m = A.size();
    int n = A[0].size();
    for(int i = 0; i < m; ++i) {
        dfs(i, 0, A);
        dfs(i, n-1, A);
    }
    for(int i = 0; i < n; ++i) {
        dfs(0, i, A);
        dfs(m-1, i, A);
    }
    for(int i = 0; i< m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(A[i][j] == 'M')
                A[i][j] = 'O';
            else
                A[i][j] = 'X';
        }
    }
}

```
```cpp
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int R = A.size();
    int C = A.front().size();
    vector<pair<int,int>> direction{{-1,0},{0,-1},{1,0},{0,1}};
    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < R && j < C;  
    };
    auto bfs = [&](int i, int j) {
        queue<pair<int,int>> q;
        q.push({i,j});
        A[i][j] = 'B';
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            for(auto & d: direction) {
                int ii = p.first + d.first;
                int jj = p.second + d.second;
                if(valid(ii,jj) && A[ii][jj] == 'O') {
                    A[ii][jj] = 'B';
                    q.push({ii,jj});
                }
            }
        }
    };
    for(int i = 0; i < R; ++i) {
        if(A[i][0] == 'O')
            bfs(i, 0);
        if(A[i][C-1] == 'O')
            bfs(i, C - 1);
    }
    for(int i = 0; i < C; ++i) {
        if(A[0][i] == 'O')
            bfs(0,i);
        if(A[R-1][i] == 'O')
            bfs(R-1,i);
    }
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(A[i][j] == 'B')
                A[i][j] = 'O';
            else
                A[i][j] = 'X';
        }
    }
}
```
