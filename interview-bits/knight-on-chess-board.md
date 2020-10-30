```cpp
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> visited(A+1, vector<int> (B+1, 0));
    vector<pair<int,int>> direction {
        {-2, -1},{-1,-2}, {1,-2}, {2,-1}, {-2, 1}, {-1, 2}, {1,2},{2,1}};
    auto valid = [&](int i,int j) {
        return i > 0 && j > 0 && i <= A && j <= B;
    };
    queue<tuple<int,int,int>> q;
    q.push({C,D,0});
    visited[C][D] = 1;
    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        int i, j, k;
        tie(i,j,k) = t;
        if(i == E && j == F)
            return k;
        for(auto & d: direction) {
            int ii = i+ d.first;
            int jj = j+ d.second;
            if(valid(ii, jj) && !visited[ii][jj]) {
                visited[ii][jj] = 1;
                q.push({ii,jj, k+1});
            }
        }
    }
    return -1;
}
```
