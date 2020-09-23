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

bool comp(ListNode* a,ListNode * b) {
        return a->val > b->val;
}
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,
            function<bool(ListNode*,ListNode*)>> pq(comp);
        for(ListNode * l: lists) {
            if(l) pq.push(l);
        }
        ListNode * head = nullptr, *tail = nullptr;
        while(!pq.empty()) {
            ListNode * cur = pq.top();
            pq.pop();
            if(cur->next) {
                pq.push(cur->next);
            }
            cur->next = nullptr;
            if(tail) {
                tail->next = cur;
                tail = cur;
            }
            else {
                tail = head = cur;
            }
        }
        return head;
    }
};
```
