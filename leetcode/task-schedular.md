```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(auto & t: tasks)
            count[t - 'A']++;
        int f_max = *max_element(count.begin(), count.end());
        int n_max = 0;
        for(int i = 0; i < count.size(); ++i)
            if(count[i] == f_max)
                n_max++;
        return max((int)tasks.size(), (f_max - 1)*(n+1)+n_max);
    }
};
```
