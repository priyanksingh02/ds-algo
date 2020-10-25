## Spiral Order Matrix I
```cpp

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    if(A.empty() or A.front().empty())
        return {};
    int m = A.size();
    int n = A[0].size();
    int i = 0;
    vector<int> ans;
    while(i < m && i < n) {
        for(int j = i; j < n; ++j) {
            ans.push_back(A[i][j]);
        }
        for(int j = i+1; j < m; ++j) {
            ans.push_back(A[j][n-1]);
        }
        if(i != m-1) {
            for(int j = n - 2; j >=i; --j) {
                ans.push_back(A[m-1][j]);
            }
        }
        if(i != n-1) {
            for(int j = m - 2; j > i; --j) {
                ans.push_back(A[j][i]);
            }
        }
        --m;
        --n;
        i++;
    }
    return ans;
}

```

## Spiral Order Matrix II
```cpp
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans (A, vector<int> (A));
    int fill = 1;
    int low = 0, high = A-1;
    while(low <= high) {
        for(int i= low; i <= high; ++i) {
            ans[low][i] = fill++;
        }
        for(int i= low + 1; i <= high; ++i) {
            ans[i][high] = fill++;
        }
        for(int i = high - 1; i >= low; --i) {
            ans[high][i] = fill++;
        }
        for(int i = high - 1; i > low; --i) {
            ans[i][low] = fill++;
        }
        low ++;
        high --;
    }
    return ans;
}
```
