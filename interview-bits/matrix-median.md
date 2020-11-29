```cpp

int Solution::findMedian(vector<vector<int> > &A) {
    if(A.empty() || A[0].empty())
        return 0;
    int imin = INT_MAX, imax = INT_MIN;
    int m = A.size();
    int n = A[0].size();
    for(int i = 0; i < m; ++i)
        imin = min(A[i][0], imin); // min in first col
    for(int i = 0; i < m; ++i)
        imax = max(A[i][n-1], imax); //max in last col
    int req_idx = (m*n+1)/2;
    // cout << imin << " " << imax << " " << req_idx << endl;
    while(imin < imax) {
        int i = imin + (imax - imin >> 1);
        int count = 0;
        for(int j = 0; j < m; ++j) {
            count += upper_bound(A[j].begin(), A[j].end(), i) - A[j].begin();
        }
        // cout << "count is " << count << endl;
        if(count < req_idx)
            imin = i+1;
        else
            imax = i;
    }
    return imin; 
}
```
```cpp

int count(vector<vector<int>> & A, int k) {
  int ans = 0;
  for(int i = 0; i < A.size(); ++i) {
    ans += upper_bound(A[i].begin(), A[i].end(), k) - A[i].begin(); 
  }
  return ans;
}

int Solution::findMedian(vector<vector<int>> &A) {
  if(A.empty() or A[0].empty()) return 0;
  int M = A.size();
  int N = A[0].size();
  int low = INT_MAX;
  for(int i= 0;i < M; ++i) {
    low = min(low, A[i][0]);
  }
  int high = INT_MIN;
  for(int i = 0; i < M; ++i) {
    high = max(high, A[i][N-1]);
  }
  int cnt = (N*M+1)/2;
  int ans = 0;
  while(low <= high) {
    int mid = low + (high - low)/2;
    // cout << mid << endl;
    if(count(A, mid) >= cnt) {
      ans =mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

```
