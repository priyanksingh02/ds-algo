```cpp


```
O(n logn)
```cpp
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        int n = bulbs.size();
        set<int> s;
        for(int i = 0; i < n; ++i) {
            s.insert(bulbs[i]);
            auto iter = s.lower_bound(bulbs[i]);
            auto upper = s.upper_bound(bulbs[i]);
            if(iter != s.begin()) {
                --iter;
                if(bulbs[i]-*iter-1 == K)
                    return i+1;
            }
            if(upper != s.end() && *upper - bulbs[i] - 1 == K)
                return i+1;
        }
        return -1;
    }
};
```

