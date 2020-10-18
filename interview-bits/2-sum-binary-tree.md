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
vector<int> nums;
void inorder(TreeNode * root) {
    if(root) {
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
}

int Solution::t2Sum(TreeNode* A, int B) {
    nums.clear();
    inorder(A);
    int i = 0;
    int j = (int)nums.size() - 1;
    while(i < j) {
        if(nums[i] + nums[j] == B) {
            return true;
        }
        if(nums[i] + nums[j] < B) {
            i++;
        }
        else {
            --j;
        }
    }
    return false;
}
```
