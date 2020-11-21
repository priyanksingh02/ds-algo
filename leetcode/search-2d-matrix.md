## Search in 2D matrix II
O(m + n)
```cpp
public class Solution {
  public boolean searchMatrix(int[][] matrix, int target) {
    int rows = matrix.length;
    int cols = matrix[0].length;
    // Start from left bottom, 
    // when matrix[x][y] > target, exclude x row by moving to top
    // when matrix[x][y] < target, exclude y column by moving to right
    int r = rows - 1;
    int c = 0;
    while (r >= 0 && c < cols) {
      if (matrix[r][c] > target) {
        r --;
      } else if (matrix[r][c] < target) {
        c ++;
      } else {
        return true;
      }
    }
    return false;
  }
}
```
O(m log n)
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
