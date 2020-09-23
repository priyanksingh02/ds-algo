## Spiral Matrix
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() or matrix.front().empty())
            return ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int imin = 0, imax = m-1;
        int jmin = 0, jmax = n - 1;
        while(imin <= imax && jmin <= jmax) {
            for(int j = jmin; j <= jmax; ++j) {
                ans.push_back(matrix[imin][j]);
            }
            for(int i = imin+1; i <= imax; ++i) {
                ans.push_back(matrix[i][jmax]);
            }
            if(imin != imax && jmin != jmax) {
                for(int j = jmax-1; j >= jmin; --j) {
                    ans.push_back(matrix[imax][j]);
                }
                for(int i = imax -1; i > imin; --i) {
                    ans.push_back(matrix[i][jmin]);
                }
            }
            imin++;
            imax--;
            jmin++;
            jmax--;
        }
        return ans;
    }
};

```
## Spiral Matrix II
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int low = 0;
        int high = n -1;
        while(low <= high) {
            for(int i = low; i <= high; ++i) {
                ans[low][i] = count++;
            }
            for(int i = low + 1; i <= high; ++i) {
                ans[i][high] = count++;
            }
            for(int i = high-1; i >= low; --i) {
                ans[high][i] = count++;
            }
            for(int i = high-1; i > low; --i) {
                ans[i][low] = count++;
            }
            low++;
            high--;
        }
        return ans;
    }
};
```
