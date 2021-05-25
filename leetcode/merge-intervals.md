```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end());
        results.push_back(intervals.front());
        for(int i= 1; i < intervals.size(); ++i) {
            if(results.back()[1] >= intervals[i][0]) {
                results.back()[1] = max(intervals[i][1], results.back()[1]);
            }
            else {
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};
```
