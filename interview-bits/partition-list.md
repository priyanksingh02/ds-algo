```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void insert(ListNode ** head, ListNode ** tail, ListNode * val) {
    if(*tail == nullptr) {
        *head = *tail = val;
    }
    else {
        (*tail)->next = val;
        (*tail) = val;
    }
}
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode * less = nullptr, *lesstail = nullptr;
    ListNode * more = nullptr, *moretail = nullptr;
    while(A) {
        ListNode * cur = A;
        A = A->next;
        cur->next = nullptr;
        if(cur->val < B) {
            insert(&less, &lesstail, cur);
        }
        else {
            insert(&more, &moretail, cur);
        }
    }
    if(less) {
        lesstail->next = more;
        return less;
    }
    else {
        return more;
    }
}
```
