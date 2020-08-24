```cpp
vector<vector<int> > Solution::fourSum(vector<int> &A, int target) {
    set<vector<int>> ans;
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < n ; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int k = j + 1;
            int l = n- 1;
            int ct = target - A[i] - A[j]; // current target
            while(k < l) {
                int cs = A[k] + A[l];
                if(ct == cs) {
                    ans.insert({A[i], A[j], A[k], A[l]});
                    k++; l--;
                }
                else if(ct < cs) {
                    l--;
                }
                else {
                    k++;
                }
            }
        }
    }
    return {ans.begin(), ans.end()};
}
```
