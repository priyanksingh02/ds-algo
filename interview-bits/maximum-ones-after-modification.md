```cpp
int Solution::solve(vector<int> &A, int B) {
    int fast = 0, slow = 0;
    int maxlen = 0;
    while(fast < A.size()) {
        if(A[fast] == 0) {
            A[fast] = -1;
            B--;
            while(B < 0 and slow <= fast) {
                if(A[slow] == -1) {
                    B++;
                }
                slow++;
            }
        }
        maxlen = max(maxlen, fast - slow + 1);
        fast++;
    }
    return maxlen;
}
```
