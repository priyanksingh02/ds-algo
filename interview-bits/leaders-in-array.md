```cpp

vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;
    int leader = 0;
    for(int i = (int)A.size() - 1; i >= 0; --i) {
        if(A[i] > leader) {
            leader = A[i];
            ans.push_back(leader);
        }
    }
    return ans;
}
```
