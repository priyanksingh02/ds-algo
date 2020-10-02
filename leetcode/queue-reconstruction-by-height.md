Efficient Solution using Segment tree
```cpp

```
Naive Solution
```cpp
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](vector<int> & a, vector<int> &b){
            return a[0] < b[0] or (a[0] == b[0] && a[1] > b[1]);
        });
        vector<vector<int>> ans(people.size(), vector<int>(2, -1));
        for(int i = 0; i < people.size(); ++i) {
            int pos = people[i][1];
            int j = 0;
            while(pos > 0 or ans[j][1] != -1) {
                if(ans[j][1] == -1)
                    pos--;
                j++;
            }
            assert(j != people.size());
            ans[j][0] = people[i][0];
            ans[j][1] = people[i][1];
        }
        return ans;
    }
};
```
