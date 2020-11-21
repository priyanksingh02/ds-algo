```cpp
Node * rev(Node* head) {
    Node * ans = nullptr;
    while(head) {
        Node * cur = head;
        head = head->next;
        cur->next = ans;
        ans = cur;
    }
    return ans;
}
bool isPalindrome(Node * head) {
    if(!head or !head->next)
        return true;
    Node * fast = head, * slow = head;
    while(fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node * b = slow->next;
    slow->next = nullptr;
    Node * a = head;
    b = rev(b);
    while(a && b && a->data == b->data) {
        a = a->next;
        b = b->next;
    }
    if(!b)
        return true;
    return false;
}
```

