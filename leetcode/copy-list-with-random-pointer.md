```cpp
class Solution {
    unordered_map<Node*, Node*> mapping;
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node * root = new Node (head->val);
        mapping[head] = root;
        root->next = copyRandomList(head->next);
        if(head->random)
            root->random = mapping[head->random];
        return root;
    }
};
```

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
struct comp {
    bool operator() (const Node * a, const Node * b) const {
        return (unsigned long long)a < (unsigned long long)b;
    }  
};

class Solution {
    map<Node*,Node*, comp> mapping;
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node * root = new Node(head->val);
        mapping[head] = root;
        root->next= copyRandomList(head->next);
        if(head->random) {
            root->random = mapping[head->random];
        }
        return root;
    }
};
```
