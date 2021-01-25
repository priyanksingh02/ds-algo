```cpp
int maxOperations(vector<int> &  nums, int k) {
  unordered_map<int,int> m;
  int ans = 0;
  for(int x: nums) {
    if(m.count(k-x)) {
      ++ans;
      if(--m[k-x] == 0) {
        m.erase(k-x);
      }
    }
    else 
      m[x]++;
  }
  return ans;
}

```
