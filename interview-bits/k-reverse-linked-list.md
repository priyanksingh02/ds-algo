```cpp

ListNode* Solution::reverseList(ListNode* root, int k) {
    if(!root || !root->next)
        return root;
    else {
        ListNode * tail = root;
        ListNode * t = root;
        ListNode * head = nullptr;
        int count = 0;
        while(count < k && t) {
            ++count;
            ListNode * cur = t;
            t = t->next;
            cur->next = head;
            head = cur;
        }
        if(t)
            tail->next = reverseList(t, k);
        return head;
    }
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
ListNode* Solution::reverseList(ListNode* root, int k) {
    if(!root)
        return nullptr;
    ListNode * ans = nullptr, * aback = nullptr;
    while(root) {
        int count = 0;
        ListNode * rev = nullptr;
        ListNode * cur = nullptr;
        while(++count <= k) {
            cur = root;
            root = root->next;
            cur->next = rev;
            rev = cur;
        }
        if(aback) {
            aback->next = rev;
        }
        else {
            aback = ans = rev;
        }
        while(aback->next)
            aback = aback->next;
    }
    return ans;
}
```
