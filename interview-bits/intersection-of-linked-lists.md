```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode * root) {
    int count = 0;
    while(root) {
        ++count;
        root = root->next;
    }
    return count;
}
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int asize = len(A);
    int bsize = len(B);
    if(asize > bsize) {
        int diff = asize - bsize;
        while(diff--) {
            A = A->next;
        }
    }
    else {
        int diff = bsize - asize;
        while(diff--) {
            B = B->next;
        }
    }
    
    while(A && B) {
        if( A == B ) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return nullptr;
}
```
