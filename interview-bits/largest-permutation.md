```cpp


vector<int> Solution::solve(vector<int> &A, int B) {
  int n = A.size();
  vector<int> hash(n+1, 0);
  for(int i = 1; i <= n; ++i) {
    hash[A[i-1]] = i;
  }
  for(int i = n; i > 0 && B > 0; --i) {
    if(i == A[n - i])
      continue;
    B--;
    int elem = A[n-i];
    swap(A[hash[i] - 1], A[n-i]);
    hash[elem] = hash[i];
    hash[i] = n-i;
  }
  return A;
}
```
