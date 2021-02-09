# In any order
```cpp
int findLongestConseqSubseq(int arr[], int N) {
  unordered_set<int> s;
  int ans = 0;
  for(int i = 0;i < N; ++i) s.insert(arr[i]);
  for(int x: s) {
    if(s.count(x-1)) continue;
    int num = x+1;
    int count = 1;
    while(s.count(num)) {
      ++count;
      ++num;
    }
    ans = max(ans, count);
  }
  return ans;
}
```
