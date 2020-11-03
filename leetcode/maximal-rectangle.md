
```cpp
class Solution {
public:
    
    int width(vector<int> & row) {
        int cur = 0;
        int maxwidth = 0;
        for(int i= 0; i < row.size(); ++i) {
            if(row[i]) {
                ++cur;
            }
            else {
                cur = 0;
            }
            maxwidth = max(maxwidth, cur);
        }
        return maxwidth;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() or matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxarea = 0;
        for(int i = 0; i < m; ++i) {
            vector<int> row(n, 1);
            for(int j = i; j < m; ++j) {
                for(int k = 0; k < n; ++k) {
                    row[k] &= (matrix[j][k] - '0');
                }
                maxarea = max(maxarea, width(row)*(j-i+1)); // height = j-i+1
            }
        }
        return maxarea;
    }
};
```

