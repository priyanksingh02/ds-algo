```cpp

vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<pair<int, pair<int,int>>> max_heap;
    vector<int> ans;
    for(int i = 0; i < A.size(); ++i) {
        max_heap.push({-A[i][0], {i, 0}});
    }
    while(!max_heap.empty()) {
        auto p = max_heap.top();
        ans.push_back(-p.first);
        max_heap.pop();
        int i = p.second.first;
        int j = p.second.second;
        if(j+1 < A[i].size()) {
            max_heap.push({-A[i][j+1], {i, j+1}});
        }
    }
    return ans;
}
```
