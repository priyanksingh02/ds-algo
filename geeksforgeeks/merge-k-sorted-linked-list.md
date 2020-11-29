```cpp
bool comp(Node* a, Node* b) { return a->data > b->data; }

Node * mergeKLists(Node * arr[], int n) {
  Node dummy(0);
  Node * tail = &dummy;
  priority_queue<Node*, vector<Node*>, function<bool(Node*,Node*)>> pq(comp);
  for(int i = 0;i < n ; ++i) {
    if(arr[i]) {
      pq.push(arr[i]);
    }
  }
  while(!pq.empty()) {
    Node * cur = pq.top(); pq.pop();
    if(cur->next) {
      pq.push(cur->next);
    }
    cur->next = nullptr;
    tail->next = cur;
    tail = cur;
  }
  return dummy.next;
}

```
