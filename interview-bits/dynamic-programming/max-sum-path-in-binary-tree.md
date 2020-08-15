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
pair<int,int> pathsum(TreeNode * root) {
    if(!root)
        return {0, INT_MIN};
    auto left = pathsum(root->left);
    auto right = pathsum(root->right);
    int f = max({root->val, root->val + left.first, root->val + right.first});
    int s = max({left.second, right.second, f, root->val + left.first + right.first});
    return {f,s};
}
 
int Solution::maxPathSum(TreeNode* A) {
    return pathsum(A).second;
}
```
