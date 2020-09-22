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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode * odd = head;
        ListNode * even = nullptr, * tail = nullptr;
        while(odd && odd->next && odd->next->next) {
            ListNode * cur = odd->next;
            odd->next = cur->next;
            odd = odd->next;
            cur->next = nullptr;
            if(tail) {
                tail->next = cur;
                tail = tail->next;
            } else {
                even = tail = cur;
            }
        }
        if(odd->next) {
            if(!tail) {
                even = tail = odd->next;
            }
            else {
                tail->next = odd->next;
                tail = tail->next;
            }
        }
        odd->next = even;
        return head;
    }
};
```
