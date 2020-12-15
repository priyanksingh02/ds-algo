```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * reverse(ListNode * root) {
    ListNode * ans = nullptr;
    while(root) {
        ListNode * cur = root;
        root = root->next;
        cur->next = ans;
        ans = cur;
    }
    return ans;
} 

ListNode* Solution::solve(ListNode* A, int B) {
    if(!A)
        return nullptr;
    ListNode * t = A;
    for(int i = 1; i < B; ++i) {
        t = t->next;
    }
    ListNode * b = t;
    ListNode * c = t->next;
    b->next = nullptr;
    b = A;
    A = reverse(A);
    b->next = c;
    if(!c)
        return A;
    t = c;
    for(int i = 1; i < B; ++i) {
        t = t->next;
    }
    t->next = solve(t->next, B);
    return A;
}
```

```cpp
ListNode* Solution::solve(ListNode* A, int B) {
    if(!A) return nullptr;
    ListNode * t = A;
    ListNode * ans = nullptr;
    ListNode * tail = nullptr;
    for(int i = 0; i < B; ++i) {
        ListNode * cur = t;
        t = t->next;
        cur->next = ans;
        ans = cur;
        if(!tail) tail = ans;
    }
    if(!t) return ans;
    tail->next = t;
    ListNode * prev = nullptr;
    for(int i = 0; i < B; ++i) {
        prev = t;
        t = t->next;
    }
    prev->next = solve(t, B);
    return ans;
    
}
```
