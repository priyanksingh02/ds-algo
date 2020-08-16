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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A)
        return nullptr;
    if(A->next == nullptr) {
        return new TreeNode(A->val);
    }
    ListNode * fast, *slow, *prev;
    fast = slow = A;
    prev = nullptr;
    while(fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = nullptr;
    TreeNode * root = new TreeNode(slow->val);
    root->left = sortedListToBST(A);
    root->right = sortedListToBST(slow->next);
    return root;
}
```
