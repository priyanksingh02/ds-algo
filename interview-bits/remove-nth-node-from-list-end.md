```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(!A)
        return nullptr;
    ListNode * fast = A;
    for(int i = 1; i <= B && fast; ++i) {
        fast = fast->next;
    }
    if(fast && fast->next) {
        ListNode * slow = A;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode * d = slow->next;
        slow->next = d->next;
        delete d;
        return A;
    }
    else {
        return A->next;
    }
}
```

```cpp
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode * fast = A;
    int i = 0;
    for(; i < B && fast; ++i) {
        fast = fast->next;
    }
    if(!fast)
        return A->next;
    ListNode * slow = A;
    while(fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return A;
}
```
