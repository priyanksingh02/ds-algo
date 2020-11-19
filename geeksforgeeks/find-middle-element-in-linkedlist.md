```cpp
int getMiddle(Node *head)
{
    Node* fast, *slow;
    fast = slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
```
