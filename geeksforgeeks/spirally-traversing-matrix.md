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
```cpp
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int> ans;
        for(int i = 0, j = r-1, k = c-1; i <= min(j,k); ++i, --j, --k) {
            for(int l = i; l <= k; ++l) {
                ans.push_back(matrix[i][l]);
            }
            for(int l = i+1; l <= j; ++l) {
                ans.push_back(matrix[l][k]);
            }
            if(i != j) {
                for(int l = k-1; l >= i; --l) {
                    ans.push_back(matrix[j][l]);
                }
            }
            if(i != k) {
                for(int l = j-1; l > i; --l) {
                    ans.push_back(matrix[l][i]);
                }
            }
        }
        return ans;
    }
};

```
