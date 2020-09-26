```cpp


int Solution::maxArea(vector<int> &A) {
  int left = 0;
  int right = (int)A.size()-1;
  long maxarea = 0;
  while(left < right) {
    long area = (long)(right - left) * min(A[left],A[right]);
    maxarea = max(maxarea, area);
    if(A[left] <= A[right])
      left++;
    else
      right--;
  }
  return maxarea;
}
```
