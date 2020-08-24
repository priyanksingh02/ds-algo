Idea: Count all possible points and select a random rectangle based on that.
Assume you have: `1 6 4` points in 3 rectangles.
Total point will be = 11.
`rand()%11` will be able to uniformly pick a random point.

    0 -> Rectangle 1
    1 - 6 -> Rectangle 2
    7 - 10 -> Rectangle 3
    
To quickly choose a rectangle, we can pick a random number , lets say `7` and 
subtract the number of points from the picked number until it becomes negative.

Note: Random number selected will be from `0 - 10`. Thus, `7` in this case will be
`8th` point and will be present in Rectangle 3.

    7 - 1 =  6
    6 - 6 = 0 
    0 - 4 = -4 (Rectangle 3 is selected)
    
Runtime : O(n)

We can do better by converting the number of points into cumulative points

    1 6 4 -> 1 7 11
    
If we find `upper_bound(7)` in the modified array, we get `2 i.e Rectangle 3`

Runtime: O(logn)

Note: After selecting a rectangle, we are just returning a random point from this
rectangle in this question.
```cpp
class Solution {
    vector<int> width;
    vector<int> height;
    vector<vector<int>> init_point;
    vector<long long> num_of_point;
public:
    Solution(vector<vector<int>>& rects) {
        srand(time(NULL));
        for(int i = 0; i < rects.size(); ++i) {
            width.push_back(rects[i][2] - rects[i][0] + 1);
            height.push_back(rects[i][3] - rects[i][1] + 1);
            init_point.push_back({rects[i][0],rects[i][1]});
            num_of_point.push_back(width.back()*height.back());
        }
        for(int i = 1; i < num_of_point.size(); ++i) {
            num_of_point[i] += num_of_point[i-1];
        }
    }
    
    vector<int> pick() {
        assert(!num_of_point.empty());
        long long random = rand()%num_of_point.back();
        auto it = upper_bound(num_of_point.begin(), num_of_point.end(), random);
        int idx = it - num_of_point.begin();
        assert(idx >= 0 && idx < init_point.size());
        int x = init_point[idx][0];
        int y = init_point[idx][1];
        if(width[idx])
            x += rand()%width[idx];
        if(height[idx])
            y += rand()%height[idx];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
 ```
