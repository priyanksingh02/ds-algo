```cpp
int minSwaps(int arr[], int N){
  vector<pair<int,int>> sorted(N);
  for(int i = 0; i < N; ++i) {
    sorted[i].first = arr[i];
    sorted[i].second = i;
  }
  sort(sorted.begin(), sorted.end());
  int ans = 0;
  vector<bool> visited (N, false);
  for(int i = 0; i < N; ++i) {
    if(visited[i] or sorted[i].second == i)
      continue;
    int len = 0;
    int u = i;
    while(!visited[u]) {
      visited[u] = true;
      u = sorted[u].second;
      ++len;
    }
    if(len > 0)
      ans += (len - 1); // cycle length - 1
  }
  return ans;
}

```
