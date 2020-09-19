```cpp
int Solution::bulbs(vector<int> &A) {
    int count = 0;
    bool press = false;
    for(int i = 0; i < A.size(); ++i) {
        // count condition:
        // press == 0 && A[i] == 0
        // press == 1 && A[i] == 1
        if(!(press^A[i])) {
            press^=1;
            ++count;
        }
    }
    return count;
}
```
