```cpp
int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> s;
    int ans=0;
    for(int i = 0; i < A.size(); ++i) {
        if(s.count(B^A[i])) {
            ++ans;
        }
        s.insert(A[i]);
    }
    return ans;
}
```
