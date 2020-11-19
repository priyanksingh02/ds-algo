```cpp
Node *flatten(Node *root)
{
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    Node * ans = nullptr, *tail = nullptr;
    while(root) {
        pq.push({root->data, root});
        root = root->next;
    }
    while(!pq.empty()) {
        auto pr = pq.top(); pq.pop();
        Node * cur = pr.second;
        if(cur->bottom) {
            pq.push({cur->bottom->data, cur->bottom});
        }
        cur->next = nullptr;
        cur->bottom = nullptr;
        if(ans) {
            tail->bottom = cur;
            tail = cur;
        }
        else {
            ans = tail = cur;
        }
    }
    return ans;
}
```

