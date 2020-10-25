## Unique binary search trees I
```cpp
vector<TreeNode*> build(int low, int high) {
    if(low > high)
        return {nullptr};
    vector<TreeNode*> ans;
    for(int i = low; i <= high; ++i) {
        auto left = build(low, i - 1);
        auto right = build(i+1, high);
        for(TreeNode * l: left) {
            for(TreeNode * r: right) {
                TreeNode * root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return ans;
}
 
vector<TreeNode*> Solution::generateTrees(int A) {
    if(!A)
        return {};
    return build(1, A);
}
```
## Unique binary search trees II
See Catalan Number;
```cpp
int Solution::numTrees(int A) {
    vector<int> dp(A+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= A; ++i) {
        for(int j = 0; j < i; ++j) {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp.back();
}
```
