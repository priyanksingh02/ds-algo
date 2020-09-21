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
    ListNode * reverse(ListNode * head) {
        if(!head || !head->next)
            return head;
        ListNode * newhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast and fast->next and fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * rev = reverse(slow->next);
        slow->next = nullptr;
        fast = rev;
        slow = head;
        while(fast && slow) {
            if(fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
```
