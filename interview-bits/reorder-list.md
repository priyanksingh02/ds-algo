```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode * reverse( ListNode * head) {
    if(!head or !head->next)
        return head;
    ListNode * newhead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}
ListNode* Solution::reorderList(ListNode* A) {
    if(!A or !A->next)
        return A;
    ListNode * fast = A, * slow = A;
    while(fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode * right = slow->next;
    slow->next = nullptr;
    right = reverse(right);
    ListNode * ans = nullptr, * tail = nullptr;
    fast = A;
    while(fast) {
        ListNode * cur = fast;
        fast = fast->next;
        cur->next = nullptr;
        if(tail) {
            tail->next = cur;
            tail = cur;
        }
        else {
            ans = tail = cur;
        }
        if(!right)
            break;
        cur = right;
        right = right->next;
        cur->next = nullptr;
        tail->next = cur;
        tail = cur;
    }
    return ans;
}
```
