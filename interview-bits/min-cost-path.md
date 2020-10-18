```cpp

int Solution::solve(int A, int B, vector<string> &C) {
    using iii= pair<int, pair<int,int>>;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    vector<vector<bool>> visited (A, vector<bool>(B, false));
    pq.push({0, {0,0}});
    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, -1, 1, 0};
    char d[4] = {'U', 'L', 'R', 'D'};
    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < A && j < B;  
    };
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int cost = p.first;
        int i = p.second.first, j = p.second.second;
        // cout << i << " " << j << " " << cost << endl;
        if(i + 1 == A && j + 1 == B)
            return cost;
        if(visited[i][j])
            continue;
        visited[i][j] = true;
        for(int k = 0; k < 4; ++k) {
            int ii = i+x[k];
            int jj = j+y[k];
            if(valid(ii, jj)) {
                // cout << "valid " << ii << ", " << jj << endl;
                if(C[i][j] == d[k])
                    pq.push({cost, {ii, jj}});
                else
                    pq.push({cost+1, {ii, jj}});
            }
            
        }
    }
    assert(false); 
    return -1; //unreachable
}
```
