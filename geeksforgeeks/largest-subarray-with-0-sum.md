```cpp
int maxLen(int A[], int n) {
  unordered_map<int,int> m;
  m[0] = 0;
  int prefix = 0;
  int maxlen = 0;
  for(int i= 0; i < n; ++i) {
    prefix+=A[i];
    if(m.count(prefix)) {
      int j = m[prefix];
      if(i+1-j > maxlen)
        maxlen = i+1-j;
    }
    else {
      m[prefix] = i+1;
    }
  }
  return maxlen;
}


```
