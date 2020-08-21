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
