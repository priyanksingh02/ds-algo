
```cpp
int Solution::candy(vector<int> &A) {
  vector<int> idx(A.size());
  for(int i = 0; i < idx.size(); ++i) {
    idx[i] = i;
  }
  sort(idx.begin(), idx.end(), [&](int a, int b) {
      return A[a] < A[b];
    });
  vector<int> candies(A.size(), 0);
  for(int i = 0; i < idx.size(); ++i) {
    int pos = idx[i];
    candies[pos] = 1;
    if(pos > 0 and A[pos-1] < A[pos])
      candies[pos] = max(candies[pos], 1 + candies[pos-1]);
    if(pos + 1 < A.size() and A[pos] > A[pos + 1])
      candies[pos] = max(candies[pos], 1 + candies[pos+1]);
  }
  int ans = 0;
  for(auto & x: candies)
    ans += x;
  return ans;
}
```
