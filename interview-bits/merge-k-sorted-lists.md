```cpp


struct comp {
    bool operator()(ListNode * a, ListNode* b) {
        return a->val > b->val;
    }  
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode *, vector<ListNode*>, comp> pq;
    for(ListNode * t: A) {
        if(t)
            pq.push(t);
    }
    ListNode * ans = nullptr, *tail = nullptr;
    while(!pq.empty()) {
        ListNode * cur = pq.top();
        pq.pop();
        if(cur->next) {
            pq.push(cur->next);
        }
        cur->next = nullptr;
        if(tail) {
            tail->next = cur;
            tail = cur;
        }
        else {
            ans = tail = cur;
        }
    }
    return ans;
}
```
