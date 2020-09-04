## Remove duplicates from sorted array II
```cpp
int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() <= 1)
        return A.size();
    int pos = -1;
    int count = 0;
    for(int i= 0; i < A.size(); ++i) {
        if(i > 0 && A[i] == A[i-1]) {
            if(count < 2) {
                ++count;
                A[++pos] = A[i];
            }
        }
        else {
            A[++pos] = A[i];
            count = 1;
        }
    }
    return pos + 1;
}
```
