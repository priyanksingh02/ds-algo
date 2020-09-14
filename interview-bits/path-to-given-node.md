```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int B) {
    if(!root)
        return {};
    if(root->val == B)
        return {B};
    vector<int> ans {root->val};
    vector<int> left = solve(root->left, B);
    if(!left.empty()) {
        ans.insert(ans.end(), left.begin(), left.end());
        return ans;
    }
    vector<int> right = solve(root->right, B);
    if(!right.empty()) {
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
    return {};
}
```

```cpp

vector<int> find(TreeNode * root, int B) {
    if(!root)
        return {};
    if(root->val == B)
        return {B};
    vector<int> left = find(root->left, B);
    if(!left.empty()) {
        left.push_back(root->val);
        return left;
    }
    vector<int> right = find(root->right, B);
    if(!right.empty()) {
        right.push_back(root->val);
        return right;
    }
    return {};
}

vector<int> Solution::solve(TreeNode* root, int B) {
    auto ans = find(root, B);
    return {ans.rbegin(), ans.rend()};
}
```
