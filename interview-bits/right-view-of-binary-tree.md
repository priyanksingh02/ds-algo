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
vector<int> Solution::solve(TreeNode* A) {
    if(!A)
        return {};
    queue<TreeNode *> q;
    q.push(A);
    vector<int> ans;
    while(!q.empty()) {
        int k = q.size();
        int last = -1;
        for(int i = 0; i < k; ++i) {
            A = q.front();
            q.pop();
            last = A->val;
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
        ans.push_back(last);
    }
    return ans;
}

```
