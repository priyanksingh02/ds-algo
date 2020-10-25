```cpp

int len(ListNode * root) {
    if(!root)
        return 0;
    return 1 + len(root->next);
} 
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int a = len(A);
    int b = len(B);
    if(b > a) {
        int dif = b - a;
        while(dif--) {
            B = B->next;
        }
    }
    else {
        int dif = a - b;
        while(dif--) {
            A = A->next;
        }
    }
    while(A && B) {
        if(A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return nullptr;
}
```
