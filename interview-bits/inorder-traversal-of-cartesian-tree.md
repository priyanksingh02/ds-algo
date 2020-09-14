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
TreeNode * build(vector<int> & a, int l, int r) {
    if(l > r)
        return nullptr;
    if(l == r)
        return new TreeNode(a[l]);
    int pos = l;
    int elem = a[l];
    for(int i = l; i <=r ; ++i) {
        if(elem < a[i]) {
            elem = a[i];
            pos = i;
        }
    }
    TreeNode * root = new TreeNode(a[pos]);
    root->left = build(a, l, pos-1);
    root->right = build(a, pos+1, r);
    return root;
} 

TreeNode* Solution::buildTree(vector<int> &A) {
    return build(A, 0, (int)A.size() - 1);
}
```
