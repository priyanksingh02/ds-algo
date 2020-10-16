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
int Solution::solve(TreeNode* A) {
    if(!A)
        return 0;
    int maxsum = 0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        int k = q.size();
        int sum = 0;
        for(int i = 0; i< k; ++i) {
            A = q.front();
            q.pop();
            sum+= A->val;
            if(A->left)
                q.push(A->left);
            if(A->right)
                q.push(A->right);
        }
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}
```
