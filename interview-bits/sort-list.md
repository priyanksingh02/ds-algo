Merge Sort
```cpp
ListNode* merge(ListNode * left, ListNode * right) {
    if(!left)
        return right;
    if(!right)
        return left;
    if(left->val <= right->val) {
        left->next = merge(left->next, right);
        return left;
    }
    else {
        right->next = merge(left, right->next);
        return right;
    }
}
ListNode* Solution::sortList(ListNode* A) {
    if(!A or !A->next) {
        return A;
    }
    ListNode * fast = A;
    ListNode * slow = A;
    while(fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode * b = slow->next;
    slow->next = nullptr;
    return merge(sortList(A), sortList(b));
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
ListNode * merge(ListNode * a, ListNode * b) {
    ListNode * root, *tail;
    root = tail = nullptr;
    while(a && b) {
        ListNode * t = nullptr;
        if(a->val <= b->val) {
            t = a;
            a = a->next;
        }
        else {
            t = b;
            b = b->next;
        }
        if(!tail) {
            tail = root = t;
        }
        else {
            tail->next = t;
            tail = tail->next;
        }
    }
    if(a) {
        if(tail) {
            tail->next = a;
        }
        else {
            root = a;
        }
    }
    if(b) {
        if(tail) {
            tail->next = b;
        }
        else {
            root = b;
        }
    }
    return root;
}
ListNode* Solution::sortList(ListNode* A) {
    if(!A || !(A->next)) {
        return A;
    }
    ListNode * fast, * slow;
    fast = slow = A;
    while(fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode * right = slow->next;
    slow->next = nullptr;
    return merge(sortList(A), sortList(right));
}
```
Quick Sort
```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * push_front(ListNode * head, ListNode * item) {
    assert(item);
    item->next = head;
    return item;
}

ListNode* Solution::sortList(ListNode* A) {
    if(!A || !A->next)
        return A;
    int pivot = A->val;
    ListNode * left , * right;
    left = right = nullptr;
    while(A) {
        ListNode * n = A->next;
        if(A->val < pivot) {
            left = push_front(left, A);
        }
        else 
            right = push_front(right, A);
        A = n; // go to next element
    }
    left = sortList(left);
    right = sortList(right);
    if(left) {
        ListNode * lback = left;
        while(lback->next)
            lback = lback->next;
        lback->next = right;
        return left;
    }
    return right;
}
```
