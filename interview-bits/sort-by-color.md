```cpp
void Solution::sortColors(vector<int> &A) {
    vector<int> count(3, 0);
    for(int i = 0; i< A.size(); ++i) {
        count[A[i]]++;
    }
    int k = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(count[k] == 0) {
            k++;
        } 
        count[k] -= 1;
        A[i] = k;
    }
    
}
```
```cpp
void Solution::sortColors(vector<int> &A) {
    
    int zero = -1, two = A.size();
    for(int i = 0; i < two; ++i) {
        if(A[i] == 0) {
            A[++zero] = 0;
        }
        else if(A[i] == 2) {
            swap(A[i], A[--two]);
            --i;
        }
    }
    for(int i = zero + 1; i < two; ++i) {
        A[i] = 1;
    }
}
```
