```cpp
void Solution::connect(TreeLinkNode* A) {
    if(!A)
        return ;
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()) {
        int n = q.size();
        TreeLinkNode * prev = nullptr;
        for(int i = 0; i < n; ++i) {
            auto p = q.front();
            q.pop();
            p->next = prev;
            prev = p;
            if(p->right)
                q.push(p->right);
            if(p->left)
                q.push(p->left);
        }
    }
}
```
