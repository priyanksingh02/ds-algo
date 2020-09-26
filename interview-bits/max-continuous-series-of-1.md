```cpp
vector<int> Solution::maxone(vector<int> &A, int B) {
  int ans = 0;
  int fast = 0, slow = 0;
  int fastpos = 0, slowpos = 0;
  while(fast < A.size()) {
    if(A[fast] == 0)
      B--;
    while(B < 0) {
      if(A[slow] == 0)
        B++;
      slow++;
    }
    if(ans < fast-slow+1) {
      ans = fast -slow + 1;
      slowpos = slow;
      fastpos = fast;
    }
    fast ++;
  }
  vector<int> answer;
  for(int i = slowpos; i <= fastpos; ++i)
    answer.push_back(i);
  return answer;
}
```
