```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = citations.size();
        while(h > 0) {
            auto lb = lower_bound(citations.begin(), citations.end(), h);
            if(citations.end() - lb >= h)
                break;
            --h;
        }
        return h;
    }
};

```
