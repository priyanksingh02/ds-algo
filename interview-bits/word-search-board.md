# Word Search Board
```cpp
static const vector<pair<int,int>> direction {{0,1},{1,0},{-1,0},{0,-1}};

bool dfs(int i, int j, int k, string& b, vector<string> & a) {
    if(k == b.size())
        return true;
    if(i < 0 or j < 0 or i >= a.size() or j >= a[0].size() or a[i][j] != b[k])
        return false;
    for(auto d: direction) {
        if(dfs(i + d.first, j + d.second, k+1, b, a))
            return true;
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    if(A.empty() or A[0].empty())
        return false;
    int m = A.size();
    int n = A[0].size();
   
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(A[i][j] == B.front()) {
                if(dfs(i,j,0, B, A))
                    return true;
            }
        }
    }
    return false;
}

```

