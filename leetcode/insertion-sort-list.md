```cpp
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * ans = nullptr;
        while(head) {
            ListNode * cur = head;
            head = head->next;
            cur->next = nullptr;
            if(!ans || ans->val >= cur->val) {
                cur->next = ans;
                ans = cur;
            }
            else {
                ListNode * fast = ans;
                ListNode * prev = ans;
                while(fast && fast->val < cur->val) {
                    prev = fast;
                    fast= fast->next;
                }
                cur->next = fast;
                prev->next = cur;
            }
        }
        return ans;
    }
};
```

