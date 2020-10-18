```cpp

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(!A) return;
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()) {
        int k = q.size();
        TreeLinkNode * prev = nullptr;
        for(int i = 0; i < k; ++i) {
            A = q.front();
            q.pop();
            A->next = prev;
            prev = A;
            if(A->right)
                q.push(A->right);
            if(A->left)
                q.push(A->left);
        }
    }
}
```
