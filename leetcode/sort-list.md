```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * merge(ListNode * a, ListNode * b) {
        if(!a)
            return b;
        if(!b)
            return a;
        if(a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        }
        else {
            b->next = merge(a, b->next);
            return b;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode * fast = head, * slow = head;
        while(fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * b = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(b));
    }
};
```
```cpp

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode * b) {
        if(!a)
            return b;
        if(!b)
            return a;
        if(a->val <= b->val) {
            a->next = merge(a->next,b);
            return a;
        }
        else {
            b->next = merge(a,b->next);
            return b;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * b = slow->next;
        slow->next = nullptr;
        ListNode * a = sortList(head);
        b = sortList(b);
        return merge(a,b);
    }
};
```
