```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();
      int cur = 0, lowest = 0, idx = -1;
      for(int i = 0; i < n; ++i) {
        cur += gas[i] - cost[i];
        if(cur < lowest) {
          idx = -1;
        }
        else if(idx == -1) {
          idx = i;
        }
        lowest = min(lowest, cur);
      }
      if(cur < 0)
        return -1;
      return idx;
    }
};
```
