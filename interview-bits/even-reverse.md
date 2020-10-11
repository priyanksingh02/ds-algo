```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void insert(ListNode ** head, ListNode ** tail, ListNode * node) {
    if(*tail) {
        (*tail)->next = node;
        (*tail) = node;
    }
    else {
        (*head) = (*tail) = node;
    }
}
ListNode * reverse(ListNode * head) {
    ListNode * ans = nullptr;
    while(head) {
        ListNode * cur = head;
        head = head->next;
        cur->next = ans;
        ans = cur;
    }
    return ans;
}
ListNode* Solution::solve(ListNode* A) {
    if(!A or !A->next)
        return A;
    ListNode * fast = A;
    ListNode * one = nullptr, * two = nullptr;
    ListNode * otail = nullptr, *ttail = nullptr;
    while(fast && fast->next) {
        ListNode * cur = fast;
        fast = fast->next;
        cur->next = nullptr;
        insert(&one, &otail, cur);
        cur = fast;
        fast = fast->next;
        cur->next = nullptr;
        insert(&two, &ttail, cur);
    }
    if(fast) {
        insert(&one, &otail, fast);
    }
    two = reverse(two);
    ListNode * ans = nullptr, * anstail = nullptr;
    while(one) {
        ListNode * cur = one;
        one = one->next;
        cur->next = nullptr;
        insert(&ans, &anstail, cur);
        if(!two)
            break;
        cur = two;
        two = two->next;
        cur->next = nullptr;
        insert(&ans, &anstail, cur);
    }
    return ans;
}
```
