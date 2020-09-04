```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A && A->next) {
        ListNode * root = A->next;
        A->next = swapPairs(root->next);
        root->next = A;
        return root;
    }
    else
        return A;
}
```
