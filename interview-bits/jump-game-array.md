```cpp

int Solution::canJump(vector<int> &A) {
    int can_reach = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(can_reach >= i) {
            can_reach = max(i + A[i], can_reach);
        }
        else
            return false;
    }
    return true;
}
```
