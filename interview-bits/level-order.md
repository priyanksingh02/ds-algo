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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    if(!A) return {};
    queue<TreeNode *> q;
    q.push(A);
    q.push(nullptr);
    vector<vector<int>> ans;
    vector<int> cur;
    while(!q.empty()) {
        TreeNode * p = q.front(); q.pop();
        if(p) {
            cur.push_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        else {
            ans.push_back(move(cur));
            cur.clear();
            if(!q.empty())
                q.push(nullptr);
        }
    }
    return ans;
}
```
