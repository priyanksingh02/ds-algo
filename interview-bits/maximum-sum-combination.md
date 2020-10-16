```cpp

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<pair<int, pair<int,int>>> max_heap;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    max_heap.push({A[0] + B[0], {0, 0}});
    set<pair<int,int>> s;
    s.insert({0,0});
    vector<int> ans;
    while(ans.size() < C) {
        auto p = max_heap.top();
        max_heap.pop();
        int i = p.second.first;
        int j = p.second.second;
        ans.push_back(p.first);
        if(i+1 < A.size() && s.insert({i+1, 0}).second) {
            max_heap.push({A[i+1] + B[0], {i+1, 0}});
        }
        if(j+1 < B.size() && s.insert({i, j+1}).second) {
            max_heap.push({A[i] + B[j+1], {i, j+1}});
        }
    }
    return ans;
}
```
