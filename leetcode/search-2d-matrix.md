## Search in 2D matrix II
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() or matrix[0].empty())
            return false;
        int lim = matrix.front().size();
        lim--;
        for(int i = 0; i < matrix.size(); ++i) {
            if(matrix[i][lim] < target)
                continue;
            int pos = lower_bound(matrix[i].begin(), matrix[i].begin() + lim + 1, target) - matrix[i].begin();
            if(matrix[i][pos] == target)
                return true;
            lim = pos;
        }
        return false;
    }
};
```
