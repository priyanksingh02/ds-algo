```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * ans, * ansback;
        ans = ansback = nullptr;
        while(head) {
            ListNode * cur = head;
            head = head->next;
            cur->next = nullptr;
            if(!ansback) {
                ans = ansback = cur;
            }
            else if(ansback->val != cur->val) {
                ansback->next = cur;
                ansback = cur;
            }
        }
        return ans;
    }
};
```
## Remove Duplicates from Sorted List II
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head && head->next) {
            if(head->val != head->next->val) {
                head->next = deleteDuplicates(head->next);
                return head;
            }
            ListNode * t = head;
            int value = t->val;
            while(t && t->val == value)
                t = t->next;
            return deleteDuplicates(t);
        }
        return head;
    }
};

```
