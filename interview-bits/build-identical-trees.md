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
int count_node(TreeNode * root) {
    if(!root)
        return 0;
    else return 1 + count_node(root->left) + count_node(root->right);
} 

int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    if(!A && !B) {
        return 0;
    }
    else if(!A && B) {
        return count_node(B);
    }
    else if(A && !B) {
        return -1;
    }
    else {
        int left = cntMatrix(A->left, B->left);
        if(left == -1)
            return -1;
        int right = cntMatrix(A->right, B->right);
        if(right == -1)
            return -1;
        return left + right;
    }
}
```
