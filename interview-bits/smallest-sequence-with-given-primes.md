```cpp

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans;
    vector<int> ref = { A, B, C};
    vector<int> nums = {A, B, C};
    vector<int> idx (3,0);
    while(ans.size() < D) {
        auto iter = min_element(nums.begin(), nums.end());
        if(ans.empty() || ans.back() != *iter)
            ans.push_back(*iter);
        int index = iter - nums.begin();
        nums[index] = ans[idx[index]]*ref[index];
        idx[index]++;
    }
    return ans;
}
```
