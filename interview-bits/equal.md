```cpp

vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int, pair<int,int>> m;
    vector<int> ans;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = i + 1; j < A.size(); ++j) {
            int sum = A[i] + A[j];
            if(m.count(sum) && m[sum].first != i && m[sum].second != j && m[sum].second != i) {
                if(ans.empty()) {
                    ans = {m[sum].first, m[sum].second, i, j};
                }
                else
                    ans = min(ans, {m[sum].first, m[sum].second, i, j});
            }
            if(m.find(sum) == m.end())
                m[sum] = {i,j};
        }
    }
    return ans;
}
```
