```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int low = 0;
        int high = n - 1;
        while(low < high) {
            int dif = high - low;
            for(int i = 0; i < dif; ++i) {
                swap(matrix[low][low+i], matrix[low+i][high]);
                swap(matrix[high-i][low],matrix[low][low+i]);
                swap(matrix[high][high-i],matrix[high-i][low]);
            }
            low++;
            high--;
        }
    }
};
```
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // vertical mirror
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};

```
