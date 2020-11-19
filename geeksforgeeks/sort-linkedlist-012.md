```cpp
Node* segregate(Node *head) {
    Node* one = nullptr, *two = nullptr, *zero = nullptr;
    while(head) {
        Node* cur = head;
        head = head->next;
        cur->next = nullptr;
        if(cur->data == 1) {
            cur->next = one;
            one = cur;
        }
        else if(cur->data == 2) {
            cur->next = two;
            two = cur;
        }
        else {
            cur->next = zero;
            zero = cur;
        }
    }
    Node * ans = nullptr;
    if(zero) {
        ans = zero;
        while(zero->next)
            zero = zero->next;
        if(one) {
            zero->next = one;
            while(one->next)
                one = one->next;
            if(two)
                one->next = two;
        }
        else {
            zero->next = two;
        }
        return ans;
    }
    else if(one) {
        ans = one;
        while(one->next)
            one = one->next;
        if(two)
            one->next = two;
        return ans;
    }
    else {
        return two;
    }
}
```

