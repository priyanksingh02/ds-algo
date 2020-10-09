```cpp

vector<int> Solution::getRow(int A) {
    vector<int> ans, prev;
    for(int i = 0; i <= A; ++i) {
        ans.push_back(1);
        if(i > 1) {
            for(int j = 1; j < prev.size(); ++j) {
                ans.push_back(prev[j]+prev[j-1]);
            }
        }
        if(i > 0)
            ans.push_back(1);
        prev = move(ans);
    }
    return prev;
}
```
