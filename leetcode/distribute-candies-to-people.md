```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans (num_people, 0);
        int count = 1;
        int pos = 0;
        while(count <= candies) {
            ans[pos] += count;
            candies -= count;
            pos = (pos + 1)%num_people;
            count++;
        }
        if(candies) {
            ans[pos] += candies; 
        }
        return ans;
    }
};
```
