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
    ListNode * ans = nullptr;
    while(root) {
        ListNode * cur = root;
        root = root->next;
        cur->next = ans;
        ans = cur;
    }
    return ans;
}

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry  = 0;
    ListNode * ans = nullptr;
    while(A || B || carry) {
        int sum = carry;
        if(A) {
            sum += A->val;
            A = A->next;
        }
        if(B) {
            sum += B->val;
            B = B->next;
        }
        ListNode * cur = new ListNode(sum%10); // store in opposite order
        cur->next = ans;
        ans = cur;
        carry = sum/10;
    }
    while(ans && ans->val == 0) { // remove leading zeroes
        ListNode * cur = ans;
        ans = ans->next;
        delete cur;
    }
    return reverse(ans);
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
