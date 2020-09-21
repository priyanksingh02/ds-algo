## Pascal's' triangle
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> row, prev;
        for(int i = 1; i <= numRows; ++i) {
            row.push_back(1);
            if(i > 2) {
                for(int j = 1; j < prev.size(); ++j) {
                    row.push_back(prev[j]+prev[j-1]);
                }
            }
            if(i > 1)
                row.push_back(1);
            ans.push_back(row);
            prev = move(row);
        }
        return ans;
    }
};
```

## Pascals triangle II
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
