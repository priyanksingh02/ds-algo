```cpp

int Solution::removeDuplicates(vector<int> &A) {
    int pos = 1;
    for(int i = 1; i < A.size(); ++i) {
        if(A[i] != A[i-1]) {
            A[pos++] = A[i];
        }
    }
    return pos;
}

```
## Remove duplicates from sorted array II
```cpp
int Solution::removeDuplicates(vector<int> &A) {
    int pos = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(i + 2 < A.size() && A[i] == A[i+2])
            continue;
        A[pos++] = A[i];
    }
    return pos;
}
```
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
