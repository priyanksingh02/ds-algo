```cpp
Node* pairWiseSwap(Node* head) {
    if(!head or !head->next)
        return head;
    Node * a = head;
    Node * b = head->next;
    Node * c = b->next;
    b->next = a;
    a->next = pairWiseSwap(c);
    return b;
}
```
