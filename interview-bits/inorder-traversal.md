Iterative Version
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
void pushall(stack<TreeNode*> & st, TreeNode * root) {
    while(root) {
        st.push(root);
        root = root->left;
    }
}

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode *> st;
    pushall(st,A);
    while(!st.empty()) {
        A = st.top();
        st.pop();
        ans.push_back(A->val);
        if(A->right)
            pushall(st, A->right);
    }
    return ans;
}
```
