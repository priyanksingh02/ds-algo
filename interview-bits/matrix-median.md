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
