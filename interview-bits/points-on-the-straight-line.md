```cpp
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        map<pair<int,int>,int> slope;
        int dup = 0;
        int other_points = 0;
        for(int j = i + 1; j < n; ++j) {
            int dx = A[j] - A[i];
            int dy = B[j] - B[i];
            if(!dx && !dy) {
                dup++;
                continue;
            }
            int gcd = __gcd(dx,dy);
            assert(gcd);
            dx = dx/gcd;
            dy = dy/gcd;
            other_points = max(other_points, ++slope[{dy,dx}]);
        }
        ans = max(ans, 1 + dup + other_points);
    }
    return ans;
}
```
```cpp

pair<int,int> slope(pair<int,int> a, pair<int,int> b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    bool sign = (x < 0) ^ (y < 0);
    x = abs(x);
    y = abs(y);
    int gcd = __gcd(x,y);
    assert(gcd > 0);
    x /= gcd;
    y /= gcd;
    if(sign)
        return {-x, y};
    return {x,y};
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if(A.empty()) return 0;
    map<pair<int,int>,int> m;
    for(int i = 0; i < A.size(); ++i) {
        m[{A[i], B[i]}]++;
    }
    int maxpoints = 0;
    for(auto & x: m) {
        map<pair<int,int>,int> s;
        maxpoints = max(maxpoints, x.second);
        for(auto & y: m) {
            if(y.first <= x.first)
                continue;
            auto sl = slope(x.first, y.first);
            s[sl] += y.second;
            maxpoints = max(maxpoints , x.second + s[sl]);
        }
    }
    return maxpoints;
}
```
```cpp
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    map<pair<int,int>,int> points;
    for(int i = 0; i < A.size(); ++i) {
        points[{A[i],B[i]}]++;
    }
    int n = points.size();
    if(n == 0)
        return 0;
    if(n == 1)
        return points.begin()->second;
    int ans = 0;
    for(auto & u: points) {
        map<pair<int, int>, int> slope;
        for(auto & v: points) {
            if(u.first != v.first) {
                // slope == a/b
                int mx = v.first.first - u.first.first;
                int my = v.first.second - u.first.second;
                int gcd = __gcd(mx,my);
                assert(gcd);
                int a = mx/gcd;
                int b = my/gcd;
                pair<int,int> m {a,b};
                if(slope.count(m) > 0) {
                    slope[m] += v.second;
                }
                else {
                    slope[m] = u.second + v.second;
                }
                ans = max(ans, slope[m]);
            }
        }
    }
    return ans;
}
```

