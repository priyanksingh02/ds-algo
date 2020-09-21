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
