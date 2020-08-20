```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * reverse(ListNode * root) {
        if(!root || !root->next) {

            return root;
        }
        ListNode * ans = reverse(root->next);
        root->next->next = root;
        root->next = nullptr;
        return ans;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return ;
        ListNode * slow, * fast;
        slow = fast = head;
        while(fast && fast->next) {

            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * rev = slow->next;
        slow->next = nullptr;
        rev = reverse(rev);
        ListNode * up, * down;
        up = head;
        down = rev;
        ListNode * ans = nullptr, *ansback = nullptr;
        while(up) {
            if(!ansback) {
                ans = ansback = up;
                up = up->next;
            }
            else {
                ansback->next = up;
                up = up->next;
                ansback = ansback->next;
            }
            if(down) {
                ansback->next = down;
                down = down->next;
                ansback = ansback->next;
            }
        }
        head = ans;
    }
};
```
