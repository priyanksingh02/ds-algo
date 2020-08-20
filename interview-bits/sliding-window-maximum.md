```cpp
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> q;
    vector<int> ans;
    for(int i = 0; i < A.size() && i < B; ++i) {
        while(!q.empty() && q.back() < A[i])
            q.pop_back();
        q.push_back(A[i]);
    }
    ans.push_back(q.front());
    for(int i = B; i < A.size(); ++i) {
        if(q.front() == A[i-B])
            q.pop_front();
        while(!q.empty() && q.back() < A[i]) {
            q.pop_back();
        }
        q.push_back(A[i]);
        ans.push_back(q.front());
    }
    return ans;
}
```
