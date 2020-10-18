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
```cpp

pair<int,int> find(TreeNode * root) {
    if(!root) {
        return {0, INT_MIN};
    }
    if(!root->left && !root->right) {
        return {root->val, root->val};
    }
    auto l = find(root->left);
    auto r = find(root->right);
    int max_height = root->val + max({0, l.first, r.first});
    int cur_max = max({max_height, l.first + root->val + r.first});
    return {max_height, max({cur_max, l.second, r.second})};
} 

int Solution::maxPathSum(TreeNode* root) {
    return find(root).second;
}
```
