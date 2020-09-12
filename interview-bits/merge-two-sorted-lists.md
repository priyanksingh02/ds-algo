```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
    if(A->val <= B->val) {
        A->next = mergeTwoLists(A->next,B);
        return A;
    }
    else {
        B->next = mergeTwoLists(A, B->next);
        return B;
    }
}
```

## Merge Two Sorted lists II

```cpp

void Solution::merge(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    A.resize(m + n);
    --m; --n;
    for(int k = m + n + 1; k >= 0; --k) {
        if(m < 0) {
            A[k] = B[n--];
        }
        else if(n < 0) {
            break;
        }
        else if(A[m] > B[n])
            A[k] = A[m--];
        else
            A[k] = B[n--];
    }
    
}
```
