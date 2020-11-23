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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * ans = nullptr, *tail = nullptr;
        while(carry or l1 or l2) {
            int sum = carry;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if(!tail) {
                ans = tail = new ListNode(sum%10);
            }
            else {
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
            carry = sum/10;
        }
        return ans;
    }
};
```
# Add Two Numbers II
Changing l1 && l2 is not allowed
```cpp
class Solution {
public:
    pair<ListNode*, int> sum(ListNode * l1, int pos1, ListNode * l2, int pos2) {
        if(pos1 == 0)
            return {l2, 0}; // l2 is ans
        if(pos2 == 0)
            return {l1, 0}; // l1 is ans
        pair<ListNode*, int> rest;
        int cur;
        if(pos1 == pos2) {
            rest = sum(l1->next, pos1 - 1, l2->next, pos2 - 1);
            cur = l1->val + l2->val + rest.second;
            
        }
        else if(pos1 > pos2) {
            rest = sum(l1->next, pos1 - 1, l2, pos2);
            cur = l1->val + rest.second;
        }
        else {
            rest = sum(l1, pos1, l2->next, pos2-1);
            cur = l2->val + rest.second;
        }
        int carry = cur/10;
        ListNode * head = new ListNode(cur%10);
        head->next = rest.first;
        return {head, carry};
    }
    
    int len(ListNode* l) {
        int cnt = 0;
        while(l) {
            ++cnt;
            l = l->next;
        }
        return cnt;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1 = len(l1);
        int s2 = len(l2);
        auto rest = sum(l1, s1, l2, s2);
        if(rest.second == 0) {
            return rest.first;
        }
        ListNode * head = new ListNode(rest.second);
        head->next = rest.first;
        return head;
    }
};

```
