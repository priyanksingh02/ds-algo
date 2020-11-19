```cpp
void removeLoop(Node* head)
{
    Node* fast = head, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            fast = head;
            if(fast == slow) { // starting point
                fast = fast->next;
                while(fast->next != slow) {
                    fast = fast->next;
                }
                fast->next = nullptr;
            }
            else { // 
                Node* prev = nullptr;
                while(slow != fast) {
                    prev = slow;
                    slow = slow->next;
                    fast = fast->next;
                }
                prev->next = nullptr;
            }
        }
    }

}
```

