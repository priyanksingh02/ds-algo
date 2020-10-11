## Reverse Link List II

```cpp
ListNode * reverse(ListNode * root) {
    if(!root or !root->next)
        return root;
    ListNode * newroot = reverse(root->next);
    root->next->next = root;
    root->next = nullptr;
    return newroot;
}

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    if(!head or !head->next) {
        return head;
    }
    ListNode * t = head, *a, *b, *c, *d;
    a = b = c = d = nullptr;
    for(int i = 1; i <= n; ++i) {
        if(i == m - 1)
            a = t;
        if(i == n)
            c = t;
        assert(t);
         t = t->next;
    }
    if(m == 1) {
        b = head;
    }
    else {
        b = a->next;
    }
    d = c->next;
    c->next = nullptr;
    reverse(b);
    if(m != 1) {
        a->next = c;
    }
    b->next = d;
    if(m == 1) {
        return c;
    }
    return head;
}
```
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * rev(ListNode* root) {
    if(!root || !root->next)
        return root;
    ListNode * newroot = rev(root->next);
    root->next->next = root;
    root->next = nullptr;
    return root;
} 
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(!A || !A->next)
        return A;
    ListNode * start = A, *end = A;
    int count = 1;
    while(count + 1 < B) {
        start = start->next;
        end = end->next;
        ++count;
    }
    while(count < C) {
        end = end->next;
        ++count;
    }
    // cout << start->val << " " << end->val << endl;
    ListNode * startnext = start->next;
    ListNode * endnext = end->next;
    end->next = nullptr;
    if(B== 1) {
        rev(start);
        start->next = endnext;
        return end;
    }
    else {
        rev(start->next);
        startnext->next = endnext;
        start->next = end;
        return A;
    }
}
```
