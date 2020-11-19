```cpp
int len(Node* head) {
    int cnt = 0;
    while(head) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

int intersectPoint(Node* head1, Node* head2)
{
    int l1 = len(head1);
    int l2 = len(head2);
    if(l1 > l2) {
        int dif = l1 - l2;
        while(dif--) {
            head1 = head1->next;
        }
    }
    else {
        int dif = l2 - l1;
        while(dif--) {
            head2 = head2->next;
        }
    }
    while(head1 && head2 && head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1 && head1 == head2) {
        return head1->data;
    }
    return -1;
}
```

