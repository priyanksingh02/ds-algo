```cpp
string Solution::solve(int A, int B, int N, int R, vector<int> &X, vector<int> &Y) {
    auto distance = [](int a, int b, int x, int y) {
        return ceil(sqrt((x-a)*(x-a) + (y-b)*(y-b)));  
    };
    vector<vector<int>> grid(A+1, vector<int> (B+1, 1));
    for(int i = 0; i <= A; ++i) {
        for(int j = 0; j <= B; ++j) {
            for(int k = 0; k < N; ++k) {
                if(distance(X[k],Y[k],i,j) <= R) {
                    grid[i][j] = 0;
                }
            }
        }
    }
    if(grid[A][B] == 0 || grid[0][0] == 0)
        return "NO";
    vector<pair<int,int>> direction {{-1,-1}, {-1,0}, {-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i <= A && j <= B;
    };
    
    queue<pair<int,int>> q;
    q.push({0,0});
    grid[0][0] = 0;
    while(!q.empty()) {
        auto & p = q.front(); q.pop();
        for(auto &d : direction) {
            int ii = p.first + d.first;
            int jj = p.second + d.second;
            if(valid(ii,jj) && grid[ii][jj]) {
                if(ii == A && jj == B)
                    return "YES";
                grid[ii][jj] = 0;
                q.push({ii,jj});
            }
        }
    }
           
    return "NO";
}
```
