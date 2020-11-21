```cpp
Node* rev(Node* head) {
    if(!head or !head->next) {
        return head;
    }
    Node * new_head = rev(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first = rev(first);
    second = rev(second);
    Node * ans = nullptr;
    int carry = 0;
    while(carry or first or second) {
        int sum = carry;
        if(first) {
            sum += first->data;
            first = first->next;
        }
        if(second) {
            sum += second->data;
            second = second->next;
        }
        Node* cur = new Node(sum%10);
        cur->next = ans;
        ans = cur;
        carry = sum/10;
    }
    return ans;
}

```

