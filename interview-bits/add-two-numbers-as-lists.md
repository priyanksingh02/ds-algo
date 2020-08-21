```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * rev(ListNode * root) {
    if(!root || !root->next) {
        return root;
    }
    ListNode * newroot = rev(root->next);
    root->next->next = root;
    root->next = nullptr;
    return newroot;
} 

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode * ans, * back;
    ans = back = nullptr;
    int carry = 0;
    while(A || B || carry) {
        int sum = 0;
        if(A) {
            sum += A->val;
            A = A->next;
        }
        if(B) {
            sum += B->val;
            B = B->next;
        }
        sum += carry;
        ListNode * cur = new ListNode(sum%10);
        carry = sum/10;
        if(!back) ans = back = cur;
        else {
            back->next = cur;
            back = back->next;
        }
    }
    ans = rev(ans);
    while(ans && ans->val == 0)
        ans = ans->next;
    if(!ans)
        return new ListNode(0);
    return rev(ans);
}
```
