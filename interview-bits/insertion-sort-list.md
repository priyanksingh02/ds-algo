```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode * ans = nullptr;
    ListNode * cur = nullptr;
    while(A) {
        cur = A;
        A = A->next;
        cur->next = nullptr;
        if(!ans) {
            ans = cur;
            continue;
        }
        ListNode * prev = nullptr;
        ListNode * t = ans;
        while(t && t->val < cur->val) {
            prev = t;
            t = t->next;
        }
        if(!prev) {
            cur->next = ans;
            ans = cur;
        }
        else {
            cur->next = prev->next;
            prev->next = cur;
        }
    }
    return ans;
}

```
```cpp
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode * root = nullptr;
    while(A) {
        ListNode * cur = A;
        A = A->next;
        cur->next = nullptr;
        if(!root || root->val >= cur->val) {
            cur->next = root;
            root = cur;
        }
        else {
            ListNode * prev = nullptr;
            ListNode * t = root;
            while(t && t->val < cur->val) {
                prev = t;
                t = t->next;
            }
            cur->next = prev->next;
            prev->next = cur;
        }
    }
    return root;
}
```

```cpp
ListNode* Solution::insertionSortList(ListNode* head) {
    ListNode * it = head;
    while(it && it->next) {
        ListNode * t = it;
        int minval = INT_MAX;
        ListNode * p = nullptr;
        while(t) {
            if(t->val < minval) {
                minval = t->val;
                p = t;
            }
            t = t->next;
        }
        assert(p);
        swap(it->val, p->val);
        it = it->next;
    }
    return head;
}
```
