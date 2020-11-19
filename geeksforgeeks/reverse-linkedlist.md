```cpp
struct Node* reverseList(struct Node *head)
{
    if(!head or !head->next)
        return head;
    Node* newroot = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newroot; 
}
```
