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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    if(!A) return {};
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(A);
    while(!st.empty()) {
        A = st.top();
        st.pop();
        ans.push_back(A->val);
        if(A->right)
            st.push(A->right);
        if(A->left)
            st.push(A->left);
    }
    return ans;
}
```
