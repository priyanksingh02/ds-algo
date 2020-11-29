```cpp
TreeNode * p = nullptr;
pair<int, int> ans;
void inorder(TreeNode * root) {
    if(root) {
        inorder(root->left);
        if(p && p->val > root->val) {
            ans.first = root->val;
            if(ans.second < 0)
                ans.second = p->val;
        }
        p = root;
        inorder(root->right);
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    p = nullptr;
    ans.first = -1; ans.second = -1;
    inorder(A);
    return {ans.first, ans.second};
}
```
```cpp
TreeNode * p; // previous to root
int larger, smaller;
void inorder(TreeNode * root) {
    if(root) {
        inorder(root->left);
        if(p && p->val > root->val) {
            larger = max(larger, p->val);
            smaller = min(smaller, root->val);
        }
        p = root;
        inorder(root->right);
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    p = nullptr;
    larger = INT_MIN, smaller = INT_MAX;
    inorder(A);
    return {smaller, larger};
}
```
