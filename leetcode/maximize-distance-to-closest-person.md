```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = 0;
        int r = (int)seats.size() - 1;
        int cur = 0;
        while(l <= r && seats[l] == 0) {
            cur++; l++;
        }
        int ans = cur;
        cur = 0;
        while(r >= l && seats[r] == 0) {
            cur++; r--;
        }
        ans = max(ans, cur);
        cur = 0;
        for(int i = l; i <= r; ++i) {
            if(seats[i] == 0) {
                ++cur;
            }
            else {
                ans = max(ans, (cur+1)/2);
                cur = 0;
            }
        }
        return ans;
    }
};

```

