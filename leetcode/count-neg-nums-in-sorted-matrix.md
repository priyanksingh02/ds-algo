```cpp
class Solution {
    
public:
    int count(vector<int> arr) {
        reverse(arr.begin(), arr.end());
        int low = 0;
        int high = (int)arr.size() - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low >> 1);
            if(arr[mid] < 0) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i = 0; i < grid.size(); ++i) {
            ans += count(grid[i]);
        }
        return ans;
    }
};
```
