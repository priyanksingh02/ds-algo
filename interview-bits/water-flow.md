```cpp
bool valid(int i, int j , int m, int n) {
    return i >= 0 && j >= 0 &&  i < m && j < n;
}
static const vector<pair<int,int>> direction {{1,0},{-1,0}, {0,1},{0,-1}};

void dfs(int i, int j, vector<vector<int>> & a, vector<vector<bool>> & visited) {
    int m = a.size();
    int n = a[0].size();
    visited[i][j] = true;
    for(auto & d: direction) {
        int ii = i+d.first;
        int jj = j+d.second;
        if(valid(ii,jj,m,n) && !visited[ii][jj] && a[ii][jj] >= a[i][j])
            dfs(ii,jj, a, visited);
    }
}

void print(vector<vector<bool>> & m) {
    for(auto & x: m) {
        for(auto  y: x)
            cout << y << " ";
        cout << endl;
    }
}

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() or A[0].empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    vector<vector<bool>> blue(m, vector<bool> (n, false));
    vector<vector<bool>> red(m, vector<bool> (n, false));
    for(int i = 0; i < m; ++i) {
        dfs(i, 0, A, blue);
        dfs(i, n-1, A, red);
    }
    for(int i = 0; i < n; ++i) {
        dfs(0, i, A, blue);
        dfs(m-1, i, A, red);
    }
    // print(blue);
    // cout << "======" << endl;
    // print(red);
    int ans = 0;
    for(int i= 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(blue[i][j] && red[i][j]) {
                ++ans;
                // cout << i << ", " << j << endl;
            }
        }
    }
    return ans;
}
```

```cpp
using vvi = vector<vector<int>>;
const vector<pair<int,int>> direction {{0,1},{1,0},{-1,0},{0,-1}};
bool valid(vvi & grid, int i, int j) {
    return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
}

void dfs(vvi& A,vvi & grid, int i , int j) {
    grid[i][j] = 1;
    for(auto & d: direction) {
        int nexti = i + d.first;
        int nextj = j + d.second;
        if(valid(grid, nexti, nextj) && A[nexti][nextj] >= A[i][j] 
            && grid[nexti][nextj] == 0) {
            dfs(A, grid, nexti, nextj);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int R = A.size();
    int C = A.front().size();
    vvi red(R, vector<int> (C,0));
    vvi blue(R, vector<int> (C,0));
    for(int i = 0; i < R; ++i) {
        dfs(A, red, i, C-1);
        dfs(A, blue, i, 0);
    }
    for(int i = 0; i < C; ++i) {
        dfs(A, red, R-1, i);
        dfs(A, blue, 0, i);
    }
    int ans = 0;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(red[i][j] + blue[i][j] == 2)
                ans+= 1;
        }   
    }
    return ans;
}
```
