```cpp
int target;
bool ans;
void path(TreeNode * root, int sum) {
    if(root) {
        sum += root->val;
        if(!root->left && !root->right && sum == target)
            ans = true;
        path(root->left, sum);
        path(root->right, sum);
    }
}
int Solution::hasPathSum(TreeNode* A, int B) {
    target = B;
    ans = false;
    path(A, 0);
    return ans;
}
```
