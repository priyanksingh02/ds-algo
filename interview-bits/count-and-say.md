```cpp
string Solution::countAndSay(int A) {
  if(A == 1) return "1";
  string prev = countAndSay(A-1);
  string ans;
  int count = 1;
  for(int i = 1; i < prev.size(); ++i) {
    if(prev[i] == prev[i-1]) {
      count++;
    }
    else {
      ans += to_string(count);
      ans.push_back(prev[i-1]);
      count = 1;
    }
  }
  ans += to_string(count);
  ans.push_back(prev.back());
  return ans;
}
```
