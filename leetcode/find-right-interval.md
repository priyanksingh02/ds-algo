```cpp
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> res(n);
        if (n == 0) return res;
        
        for(int i = 0;i<n;i++) {
            res[i] = nums[i][1];
            nums[i][1] = i;
        }
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i<n;i++) {
            int end = res[i];
            
            int l = 0, r = n-1, mid, resI = -1;
            while(l <= r) {
                mid = l + (r-l)/2;
                if (nums[mid][0] >= end) {
                    resI = nums[mid][1];
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            res[i] = resI;
        }
        return res;
    }
};
```
O(nlogn)
```cpp
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<tuple<int,int,int>> points;
        for(int i = 0; i < n; ++i) {
            points.push_back({intervals[i][0],intervals[i][1], i});
        }
        vector<int> xvalues(n);
        sort(points.begin(), points.end());
        for(int i = 0; i < n; ++i) {
            xvalues[i] = get<0>(points[i]);
        }
        vector<int> ans (n, -1);
        for(int i = n - 1; i >= 0; --i) {
            int yval = intervals[i][1];
            auto it = lower_bound(xvalues.begin(), xvalues.end(), yval);
            if(it != xvalues.end()) {
                int pos = it - xvalues.begin();
                ans[i] = get<2>(points[pos]);
            }
            else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
```
