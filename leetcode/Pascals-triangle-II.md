```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; ++i) {
            vector<int> t;
            t.push_back(1);
            if(i > 1) {
                for(int j = 1; j < ans.size(); ++j) {
                    t.push_back(ans[j] + ans[j-1]);
                }
            }
            if(i > 0)
                t.push_back(1);
            ans = t;
        }
        return ans;
    }
};

```
