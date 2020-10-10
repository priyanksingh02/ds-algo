```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* root) {
    if(!root)
        return root;
    ListNode * A = root;
    while(A->next) {
        if(A->val == A->next->val) {
            ListNode * cur = A->next;
            A->next = A->next->next;
            delete cur;
        }
        else {
            A = A->next;
        }
    }
    return root;
}
```
```cpp
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A or !A->next)
        return A;
    if(A->val == A->next->val) {
        return deleteDuplicates(A->next);
    }
    A->next = deleteDuplicates(A->next);
    return A;
}
```

## Remove Duplicate from sorted list II

```cpp
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A or !A->next)
        return A;
    if(A->val != A->next->val) {
        A->next = deleteDuplicates(A->next);
        return A;
    }
    if(!A->next->next) {
        return nullptr;
    }
    if(A->val == A->next->next->val) {
        return deleteDuplicates(A->next);
    }
    return deleteDuplicates(A->next->next);
}
```

```cpp
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A && A->next) {
       if(A->val == A->next->val) {
           ListNode * t = A;
            while(t && t->next && t->val == t->next->val)
                t = t->next;
            if(!t->next)
                return nullptr;
            return deleteDuplicates(t->next);
       }
       else {
           A->next = deleteDuplicates(A->next);
       }
    }
    return A;
}
```
