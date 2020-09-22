```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode * head) {
        int count = 0;
        while(head) {
            ++count;
            head = head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA);
        int lenB = len(headB);
        int dif = abs(lenA-lenB);
        if(lenA > lenB) {
            while(dif--) {
                headA = headA->next;
            }
        }
        else {
            while(dif--) {
                headB = headB->next;
            }
        }
        while(headA && headB) {
            if(headA == headB) {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};
```
