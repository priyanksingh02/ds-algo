# Combination Sum II
```cpp
vector<vector<int>> combinationSum(vector<int> & A, int N, int B) {
  int limit = 1<<N;
  set<vector<int>> ans;
  sort(A.begin(), A.end());
  for(int i = 0;i < limit; ++i) {
    vector<int> row;
    int sum = 0;
    for(int j = 0; j < N; ++j) {
      if(i & (1 << j)) {
        sum += A[j];
        row.push_back(A[j]);
      }
    }
    if(sum == B) {
      ans.insert(row);
    }
  }
  return {ans.begin(), ans.end()};
}
```
