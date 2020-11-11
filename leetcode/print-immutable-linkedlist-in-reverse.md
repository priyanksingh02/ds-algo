```cpp
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(head->getNext())
            printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};
```

