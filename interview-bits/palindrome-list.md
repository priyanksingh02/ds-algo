```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * reverse(ListNode* root) {
    if(!root || !root->next)
        return root;
    ListNode * newroot = reverse(root->next);
    root->next->next = root;
    root->next = nullptr;
    return newroot;
}

int Solution::lPalin(ListNode* A) {
    ListNode * fast = A;
    ListNode * slow = A;
    while(fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode * right = reverse(slow->next);
    slow->next = nullptr;
    ListNode * left = A;
    while(left && right && left->val == right->val) {
        left = left->next;
        right = right->next;
    }
    if(right)
        return false;
    if(left and left->next)
        return false;
        
    return true;
}
```

```cpp
ListNode* rev(ListNode* head) {
    ListNode * ans = nullptr;
    while(head) {
        ListNode * cur =head;
        head = head->next;
        cur->next = ans;
        ans = cur;
    }
    return ans;
}
 
int Solution::lPalin(ListNode* A) {
    if(!A or !A->next) return true;
    ListNode * fast, * slow;
    fast = slow = A;
    while(fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode * B = slow->next;
    slow->next = nullptr;
    B = rev(B);
    while(A && B && A->val == B->val) {
        A = A->next;
        B = B->next;
    }
    return !B;
}
```
