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
vector<int> Solution::solve(TreeNode* A, int B) {
    if(!A || A->val == B)
        return {};
    queue<TreeNode*> q;
    q.push(A);
    q.push(nullptr);
    bool done =false, fill = false;
    vector<int> ans;
    while(!q.empty()) {
        TreeNode * root = q.front(); q.pop();
        if(fill)
            ans.push_back(root->val);
        else if(!root) {
            if(done) {
                fill = true;
            }
            else {
                if(!q.empty())
                    q.push(nullptr);
            }
        }
        else {
            if((root->left && root->left->val == B) or (root->right && root->right->val == B)) {
                done = true;
            }
            else {
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
    }
    
    return ans;
    
}
```
