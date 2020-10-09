## Spiral Order Matrix II
```cpp
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> ans (A, vector<int> (A));
    int fill = 1;
    int low = 0, high = A-1;
    while(low <= high) {
        for(int i= low; i <= high; ++i) {
            ans[low][i] = fill++;
        }
        for(int i= low + 1; i <= high; ++i) {
            ans[i][high] = fill++;
        }
        for(int i = high - 1; i >= low; --i) {
            ans[high][i] = fill++;
        }
        for(int i = high - 1; i > low; --i) {
            ans[i][low] = fill++;
        }
        low ++;
        high --;
    }
    return ans;
}
```
