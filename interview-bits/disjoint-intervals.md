```cpp
int Solution::solve(vector<vector<int> > &A) {
  vector<pair<int,int>> vals;
  sort(A.begin(), A.end());
  for(int i = 0; i < A.size(); ++i) {
    if(vals.empty() or vals.back().second < A[i][0])
      vals.push_back({A[i][0], A[i][1]});
    else {
      if(vals.back().second > A[i][1]) {
        vals.back().first = A[i][0];
        vals.back().second = A[i][1];
      }
    }
  }
  return vals.size();
}
```
```cpp

int Solution::solve(vector<vector<int> > &A) {
    if(A.size() < 2)
        return A.size();
    int ans = 0;
    int idx = 0;
    sort(A.begin(), A.end());
    for(int i = 1; i< A.size(); ++i) {
        if(A[i][0] <= A[idx][1]) {
            if(A[i][1] <= A[idx][1])
                idx = i;
        }    
        else {
            idx = i;
            ++ans;
        }
    }
    return ans + 1;
}
```
