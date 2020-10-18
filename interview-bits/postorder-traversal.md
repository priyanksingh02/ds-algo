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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(A);
    while(!st.empty()) {
        A = st.top();
        st.pop();
        ans.push_back(A->val);
        if(A->left)
            st.push(A->left);
        if(A->right)
            st.push(A->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

```
