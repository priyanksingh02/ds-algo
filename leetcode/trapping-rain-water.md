```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            cur = max(cur, height[i]);
            left[i] = max(left[i], cur);
        }
        cur = 0;
        for(int i = n - 1; i >= 0; --i) {
            cur = max(cur, height[i]);
            right[i] = max(right[i], cur);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += max(min(left[i], right[i]) - height[i], 0);
        }
        return ans;
    }
};
```
