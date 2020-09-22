Steps:
* Go to extreme left
* Print the root
* if right exists, repeat
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        while(!st.empty()) {
            root = st.top();
            st.pop();
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            while(!root->right && !st.empty()) {
                root = st.top();
                st.pop();
                ans.push_back(root->val);
            }
            if(root->right) {
                st.push(root->right);
            }
        }
        return ans;
    }
};
```
