```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode * zhead, * ztail, * ohead;
    zhead = ztail = ohead = nullptr;
    while(A) {
        ListNode * cur = A;
        A = A->next;
        cur->next = nullptr;
        if(cur->val) {
            cur->next = ohead;
            ohead = cur;
        }
        else {
            if(ztail) {
                ztail->next = cur;
                ztail = cur;
            }
            else {
                zhead = ztail = cur;
            }
        }
        
    }
    if(zhead) {
        ztail->next = ohead;
        return zhead;
    }
    else {
        return ohead;
    }
}
```
