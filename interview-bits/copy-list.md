```cpp

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* copy(RandomListNode * head, unordered_map<long, RandomListNode *> & addr) {
    if(!head) {
        return head;
    }
    RandomListNode * newhead = new RandomListNode (head->label);
    addr[(long)head] = newhead;
    newhead->next = copy(head->next, addr);
    newhead->random = addr[(long)head->random];
    return newhead;
} 
 
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<long, RandomListNode*> addr;
    addr[(long)nullptr] = nullptr;
    return copy(A, addr);
}
```
