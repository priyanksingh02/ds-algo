```cpp
class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(!head)
        return nullptr;
      int i = 0;
      ListNode* fast = head;
      for(; i < k && fast; ++i) {
        fast = fast->next;
      }
      if(!fast && i != k) {
        return head;
      }
      ListNode * ans = nullptr;
      ListNode * slow = head;
      while(slow != fast) {
        ListNode* cur = slow;
        slow = slow->next;
        cur->next = ans;
        ans = cur;
      }
      head->next = reverseKGroup(fast, k);
      return ans;
    }
};
```
