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
bool ans;
int check(TreeNode * root) {
    if(!root)
        return 0;
    int l = check(root->left);
    int r = check(root->right);
    if(abs(l - r) > 1)
        ans = false;
    return 1 + max(l,r);
}
int Solution::isBalanced(TreeNode* A) {
    ans = true;
    check(A);
    return ans;
}
```

```cpp
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return check(root).first;
    }
    
    pair<bool,int> check(Node * root) {
        if(!root)
            return {true, 0};
        auto l = check(root->left);
        auto r = check(root->right);
        if(!l.first or !r.first or abs(l.second - r.second) > 1) {
            return {false, 0};
        }
        return {true, 1 + max(l.second, r.second)};
        
    }
};
```
