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
TreeNode* build(const vector<int> & A, int low, int high) {
    if(low > high) {
        return nullptr;
    }
    if(low == high) {
        return new TreeNode (A[low]);
    }
    int mid = low + (high - low)/2;
    TreeNode * root = new TreeNode(A[mid]);
    root->left = build(A, low, mid -1 );
    root->right = build(A, mid+1, high);
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return build(A, 0, (int)A.size() -1);
}
```
