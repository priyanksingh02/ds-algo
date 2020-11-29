```cpp
int Solution::solve(string s) {
  int n = s.size();
  string r = s;
  reverse(r.begin(), r.end());
  s += "#" + r;
  int len = 0;
  vector<int> lps(s.size(), 0);
  int i = 1;
  while(i < s.size()) {
    if(s[i] == s[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else {
      if(len != 0) {
        len = lps[len - 1];
      }
      else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return n - len;
}
```
