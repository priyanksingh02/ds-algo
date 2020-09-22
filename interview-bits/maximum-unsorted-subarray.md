```cpp

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    vector<int> b = A;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i) {
        if(A[i] != b[i]) {
            int pos = i;
            for(int j = i+1; j< n; ++j) {
                if(A[j]  != b[j])
                    pos = j;
            }
            return {i,pos};
        }
    }
    return {-1};
}
```
