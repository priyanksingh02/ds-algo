```cpp
int Solution::maxp3(vector<int> &A) {
  sort(A.begin(), A.end());
  assert(A.size() >= 3);
  int n = A.size();
  int p0 = A[0]*A[1]*A[n-1];
  int p1 = A[n-1]*A[n-2]*A[n-3];
  return max(p0, p1);
}
```
