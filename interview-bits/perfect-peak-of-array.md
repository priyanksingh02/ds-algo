```cpp

int Solution::perfectPeak(vector<int> &A) {
   int n = A.size();
   vector<int> m (n, INT_MAX);
   int minelem = INT_MAX;
   for(int i = n - 1; i >= 0; --i) {
       m[i] = minelem;
       minelem = min(minelem, A[i]);
   }
   int maxelem = A[0];
   for(int i = 1; i < n-1; ++i) {
       if(A[i] > maxelem && A[i] < m[i])
            return true;
        maxelem = max(maxelem, A[i]);
   }
   return false;
}
```
