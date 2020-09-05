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
