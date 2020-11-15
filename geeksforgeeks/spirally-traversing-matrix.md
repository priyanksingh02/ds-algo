```cpp
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    int l = 0;
    vector<int> ans;
    while(l < r && l < c) {
        for(int i= l; i < c; ++i) {
            ans.push_back(matrix[l][i]);
        }
        for(int i = l+1; i < r; ++i) {
            ans.push_back(matrix[i][c-1]);
        }
        if(l + 1 != r) {
            for(int i = c-2; i>= l; --i) {
                ans.push_back(matrix[r-1][i]);
            }
        }
        if(l + 1 != c) {
            for(int i = r-2; i > l; --i) {
                ans.push_back(matrix[i][l]);
            }
        }
        l++;
        r--;
        c--;
    }
    return ans;

}

```
