# Max Rectangle in binary Matrix
```cpp
int width(const vector<int> & row) {
    int w = 0, maxwidth = 0;
    for(int i = 0; i < row.size(); ++i) {
        if(row[i] == 1) {
            w++;   
        }
        else {
            w = 0;
        }
        maxwidth = max(maxwidth, w);
    }
    return maxwidth;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int area = 0;
    for(int i= 0; i < m; ++i) {
        vector<int> row (n, 1);
        for(int j = i; j < m; ++j) {
            for(int k = 0; k < n; ++k) {
                row[k] &= A[j][k];
            }
            area = max(area, width(row)*(j-i+1)); // height = j-i+1;
        }
    }
    return area;
}
```
