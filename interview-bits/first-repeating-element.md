```cpp
int Solution::solve(vector<int> &A) {
    int ans = -1;
    unordered_set<int> s;
    for(int i = (int)A.size()-1; i >= 0; --i) {
        if(!s.insert(A[i]).second)
            ans = A[i];
    }
    return ans;
}
```
```cpp

int Solution::solve(vector<int> &A) {
    unordered_map<int, int> pos;
    int ans = -1;
    int anspos = A.size();
    for(int i = 0; i < A.size(); ++i) {
        if(pos.count(A[i])) {
            if(anspos > pos[A[i]]) {
                anspos = pos[A[i]];
                ans = A[i];
            }
        }
        else {
            pos[A[i]] = i;   
        }
    }
    return ans;
}
```
