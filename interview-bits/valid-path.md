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

```cpp

bool inside_circle(int a, int b, int r, vector<int> & x, vector<int> & y) {
    int rsq = r*r;
    for(int i= 0; i < x.size(); ++i) {
        int asq = abs(a-x[i]);
        asq *= asq;
        int bsq = abs(b-y[i]);
        bsq *= bsq;
        if(asq+bsq <= rsq)
            return true;
    }
    return false;
}
 
string Solution::solve(int x, int y, int n, int r, vector<int> &A, vector<int> &B) {
    if(inside_circle(0,0, r, A, B) || inside_circle(x,y,r,A,B))
        return "NO";
    vector<vector<bool>> visited(x+1, vector<bool> (y+1, false));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    vector<pair<int,int>> direction = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i <= x && j <= y;  
    };
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        if(p.first ==x && p.second == y)
            return "YES";
        for(auto & d: direction) {
            int i = p.first + d.first;
            int j = p.second + d.second;
            if(valid(i, j) && !visited[i][j] && !inside_circle(i,j,r, A,B)) {
                visited[i][j] = true;
                q.push({i,j});
            }
        }
    }
    return "NO";
}
```
