```cpp
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(!A) {
        return nullptr;
    }
    if(!A->next) {
        return new TreeNode(A->val);
    }
    ListNode * fast = A;
    ListNode * slow = A;
    ListNode * prev = nullptr;
    while(fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    TreeNode * root = new TreeNode (slow->val);
    assert(prev);
    prev->next = nullptr;
    root->left = sortedListToBST(A);
    root->right = sortedListToBST(slow->next);
    return root;
}
```
