```cpp
struct node *reverse (struct node *head, int k)
{ 
    if(!head)
        return nullptr;
    int t = k;
    node * tail = nullptr, *ans = nullptr;
    node * iter = head;
    while(iter && t--) {
        node * cur = iter;
        iter = iter->next;
        cur->next = nullptr;
        if(!ans) {
            ans = tail = cur;
        }
        else {
            cur->next = ans;
            ans =cur;
        }
    }
    tail->next = reverse(iter, k);
    return ans;
}

```
