```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode * fast = A;
    int slow = 0;
    while(fast && fast->next) {
        ++slow;
        fast = fast->next->next;
    }
    if(slow - B < 0)
        return -1;
    else {
        fast = A; // re-use fast pointer
        slow -= B;
        while(slow > 0) {
            fast = fast->next;
            slow--;
        }
        return fast->val;
    }
}
```
