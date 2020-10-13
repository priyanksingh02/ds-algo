```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<pair<int,int>, bool>> points;
        for(auto & v: buildings) {
            // start == false // end == true;
            points.emplace_back(make_pair(v[0],v[2]), false);
            points.emplace_back(make_pair(v[1],v[2]), true);
        }
        sort(points.begin(), points.end(), [](const auto & a, const auto & b){
            if(a.first.first == b.first.first) { // first point matches
                if(a.second == b.second) { // both either starting point or ending point
                    if(a.second) { // ending point
                        return a.first.second < b.first.second; // lower end point processed first
                    }
                    else {
                        return a.first.second > b.first.second; // higher starting point processed first
                    }
                }
                return a.second < b.second; // starting point first
            }
            return a.first.first < b.first.first;
        });
        multiset<int> nums;
        nums.insert(0);
        int curmax = 0;
        vector<vector<int>> ans;
        for(int i = 0; i < points.size(); ++i) {
            if(points[i].second) { // end point
                auto iter = nums.find(points[i].first.second);
                if(iter != nums.end())
                    nums.erase(iter);
                int newmax = *nums.rbegin();
                if(newmax < curmax) {
                    curmax = newmax;
                    ans.push_back({points[i].first.first, curmax});
                }
            }
            else { // start point
                nums.insert(points[i].first.second);
                int newmax = *nums.rbegin();
                if(newmax > curmax) {
                    curmax = newmax;
                    ans.push_back({points[i].first.first, curmax});
                }
            }
        }
        return ans;
    }
};
```
