```cpp
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int m = B.size();
    int n = B[0].size();
    auto comp = [&](const pair<int,int> & a, const pair<int,int> & b) {
        return B[a.first][a.second] > B[b.first][b.second];  
    };
    vector<pair<int,int>> idx;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            idx.push_back({i,j});
        }
    }
    sort(idx.begin(), idx.end(), comp);
    auto dis = [](int a, int b, int i, int j) {
        return abs(a-i) + abs(b-j);  
    };
    vector<vector<int>> ans (m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < idx.size(); ++k) {
                if(dis(i,j, idx[k].first, idx[k].second) <= A) {
                    ans[i][j] = B[idx[k].first][idx[k].second];
                    break;
                }
            }
        }
    }
    return ans;
}
```
