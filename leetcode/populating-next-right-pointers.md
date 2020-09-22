```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* r) {
        if(!r)
            return nullptr;
        queue<Node*> q;
        q.push(r);
        q.push(nullptr);
        Node * root;
        Node * prev = nullptr;
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(root) {
                root->next = prev;
                prev = root;
                if(root->right)
                    q.push(root->right);
                if(root->left)
                    q.push(root->left);
            }
            else {
                prev = nullptr;
                if(!q.empty())
                    q.push(nullptr);
            }
        }
        return r;
    }
};
```
