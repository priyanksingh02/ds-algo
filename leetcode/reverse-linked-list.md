## Reverse Linked List
```cpp

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode * newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    
    // ListNode* reverseList(ListNode* head) {
    //     ListNode * ans = nullptr;
    //     while(head) {
    //         ListNode * cur = head;
    //         head = head->next;
    //         cur->next = ans;
    //         ans = cur;
    //     }
    //     return ans;
    // }
};
```

## Reverse Linked List II
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
    ListNode * rev(ListNode * root) {
        if(!root || !root->next)
            return root;
        ListNode * newroot = rev(root->next);
        root->next->next = root;
        root->next = nullptr;
        return newroot;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head or !head->next)
            return head;
        ListNode * t = head;
        ListNode * start = nullptr;
        ListNode * end = nullptr;
        for(int i = 1; i <= n; ++i) {
            if(i == m - 1)
                start = t;
            if(i == n)
                end = t;
            t = t->next;
        }
        assert(end);
        if(!start) {
            ListNode * startnext = head;
            ListNode * endnext = end->next;
            end->next = nullptr;
            rev(head);
            startnext->next = endnext;
            return end;
        }
        else {
            ListNode * startnext = start->next;
            ListNode * endnext = end->next;
            end->next = nullptr;
            rev(startnext);
            start->next = end;
            startnext->next = endnext;
            return head;
        }
    }
};
```
