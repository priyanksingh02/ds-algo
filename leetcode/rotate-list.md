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
ListNode * r (ListNode* root) {
    ListNode * ans = nullptr;
    while(root) {
        ListNode * cur = root;
        root = root->next;
        cur->next = ans;
        ans = cur;
    }
    return ans;
}

int len(ListNode * root) {
    int count = 0;
    while(root) {
        count++;
        root = root->next;
    }
    return count;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        ListNode*fast = head;
        k %= len(head);
        if(k == 0)
            return head;
        // cout << k << " " << len(head) << endl;
        int count = 1;
        while(fast && count < k) {
            fast = fast->next;
            count++;
        }
        if(!fast)
            return head;
        // cout << "fast is " << fast->val << endl;
        ListNode * slow = head;
        ListNode * rev = nullptr;
        while(fast->next) {
            ListNode * cur = slow;
            slow = slow->next;
            fast = fast->next;
            cur->next = rev;
            rev = cur;
        }
        fast->next = r(rev);
        return slow;
    }
};
```
