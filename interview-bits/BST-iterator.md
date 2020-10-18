```cpp

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> first;
stack<TreeNode*> second;
int nxt;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!first.empty())
        first.pop();
    while(!second.empty())
        second.pop();
    if(root)
        first.push(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    while(!first.empty()) {
        TreeNode * it = first.top();
        first.pop();
        while(it) {
            second.push(it);
            it = it->left;
        }
    }
    if(second.empty())
        return false;
    TreeNode * small = second.top();
    second.pop();
    if(small->right)
        first.push(small->right);
    nxt = small->val;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    return nxt;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 ```
 
 ```cpp
stack<TreeNode *> st;
void pushall(TreeNode * root) {
    while(root) {
        st.push(root);
        root = root->left;
    }
}

BSTIterator::BSTIterator(TreeNode *root) {
    while(!st.empty())
        st.pop();
    pushall(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode * tmp = st.top();
    st.pop();
    if(tmp->right)
        pushall(tmp->right);
    return tmp->val;
}

```
 ```cpp
 class BSTIterator {
    public:
        stack<TreeNode *> myStack;

        BSTIterator(TreeNode *root) {
            pushAll(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !myStack.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode *tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);
            return tmpNode->val;
        }

    private:
        void pushAll(TreeNode *node) {
            while (node != NULL) {
                myStack.push(node);
                node = node->left;
            }
        }
};
```
