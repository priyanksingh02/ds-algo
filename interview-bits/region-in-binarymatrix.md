```cpp

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty() or A.front().empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    int ans = 0;
    vector<pair<int,int>> direction {
      {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}  
    };
    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;  
    };
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(A[i][j]) {
                queue<pair<int,int>> q;
                A[i][j] = 0;
                int cur = 1;
                q.push({i,j});
                while(!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    // ans = max(p.second, ans);
                    for(auto &d : direction) {
                        int ii = p.first + d.first;
                        int jj = p.second + d.second;
                        if(valid(ii, jj) && A[ii][jj]) {
                            A[ii][jj] = 0;
                            cur += 1;
                            q.push({ii,jj});
                        }
                    }
                }
                ans = max(ans, cur);
            }
        }
    }
    return ans;
}
```
