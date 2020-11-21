```cpp
int getNthFromLast(Node *head, int n)
{
    if(!head)
        return -1;
    Node * fast = head, * slow = head;
    int i = 0;
    for(;i < n && fast; ++i) {
        fast = fast->next;
    }
    if(!fast)
        return (i==n)?head->data:-1;
    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

```
