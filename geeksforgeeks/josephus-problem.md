Recursive Solution
```cpp
int josephus(int n, int k) {
  if(n == 1)
    return 1;
  else 
    return (josephus(n-1,k) + k - 1)%n + 1;
}

```
Brute Force
```cpp

int josephus(int n, int k) {
  vector<bool> pos(n, true);
  int cnt = 0;
  int kill_cnt = 1;
  int iter = 0;
  while(kill_cnt < n) {
    if(pos[iter]) {
      ++cnt;
      if(cnt == k) {
        cnt = 0;
        pos[iter] = false;
        kill_cnt++;
      }
    }
    iter = (iter+1)%n;
  }
  for(int i = 0;i < n; ++i) {
    if(pos[i])
      return i + 1;
  }
  return 0; // dummy
}

```
