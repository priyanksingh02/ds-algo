A[i] = A[j] + k

1 3 5
i   j

j - i = 2
j - i = 4
given k is non-neg 
=> i won't cross j

Also, i != j

dif = j - i;
if(dif < k)
-> increase j
if(dif > k)
-> increase i
```cpp

int Solution::diffPossible(vector<int> &A, int B) {
    int i = 0, j = 0;
    while(j < A.size()) {
        if(i == j) {
            j++;
            continue;
        }
        int dif = A[j] - A[i];
        if(dif == B)
            return true;
        if(dif < B)
            j++;
        else
            i++;
    }
    return false;
}
```
