```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* head) {
    int ans = 0;
    while(head) {
        ++ans;
        head = head->next;
    }
    return ans;
}
ListNode* Solution::rotateRight(ListNode* head, int k) {
    if(!head)
        return nullptr;
    int l = len(head); 
    k %= l;
    if(!k)
        return head;
    ListNode * fast = head;
    for(int i = 0; i < k; ++i) {
        fast = fast->next;
    }
    ListNode * slow = head;
    while(fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode * newhead = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return newhead;
}
```
