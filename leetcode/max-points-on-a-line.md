```cpp
class Solution {
public:
    pair<int,int> get_slope(const vector<int> & a, const vector<int> & b) {
        pair<int, int> ans;
        ans.first = b[0] - a[0];
        ans.second = b[1] - a[1];
        bool sign = (ans.first < 0) ^ (ans.second < 0);
        ans.first = abs(ans.first);
        ans.second = abs(ans.second);
        int g = __gcd(ans.first, ans.second);
        if(g > 1) {
            ans.first /= g;
            ans.second /= g;
        } 
        if(sign) {
            return {-ans.first, ans.second};
        }
        else {
            return {ans.first, ans.second};
        }
    }
    
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();
        int n = points.size();
        map<vector<int>, int> p;
        for(auto & x: points) {
            p[x]++;
        }
        int maxpoints = 0;
        for(auto & x: p) {
            maxpoints = max(maxpoints, x.second);
            map<pair<int,int>, int> m;
            for(auto & y: p) {
                if(x.first <= y.first) {
                    continue;
                }
                auto slope = get_slope(x.first, y.first);
                m[slope] = max(x.second + y.second, m[slope] + y.second);
                maxpoints = max(maxpoints, m[slope]);
            }
        }
        return maxpoints;
    }
};
```
