```cpp
Node* rotate(Node* head, int k)
{
    Node * fast = head, * prev = nullptr;
    while(k--) {
        prev = fast;
        fast = fast->next;
    }
    if(!fast)
        return head;
    Node * new_head = fast;
    prev->next = nullptr;
    while(fast->next)
        fast = fast->next;
    fast->next = head;
    return new_head;
}
```

