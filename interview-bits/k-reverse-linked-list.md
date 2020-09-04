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
