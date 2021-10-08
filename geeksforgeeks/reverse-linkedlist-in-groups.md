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
```cpp
class Solution
{
    public:
    node * rev(node * head) {
        node * ans = nullptr;
        while(head) {
            node * tmp = head;
            head = head->next;
            tmp->next = ans;
            ans = tmp;
        }
        return ans;
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head) return head;
        node dummy(0);
        node * ans = &dummy;
        node * future = head;
        while(future) {
            node * front = future;
            node * tail = future;
            int i = 1;
            while(i < k && tail->next) {
                ++i;
                tail = tail->next;
            }
            future = tail->next;
            tail->next = nullptr;
            rev(front);
            ans->next = tail;
            ans = front;
        }
        return dummy.next;
    }
};
```
