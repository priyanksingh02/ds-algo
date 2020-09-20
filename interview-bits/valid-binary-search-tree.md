```cpp

bool test(TreeNode * root, int low , int high) {
    if(!root)
        return true;
    if(root->val < low || root->val > high)
        return false;
    return test(root->left, low, root->val - 1) && test(root->right, root->val + 1, high);
} 

int Solution::isValidBST(TreeNode* A) {
    return test(A, INT_MIN, INT_MAX);
}
```
