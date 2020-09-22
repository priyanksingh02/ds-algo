```cpp

void Solution::rotate(vector<vector<int> > &A) {
    int low = 0;
    int high = (int)A.size() - 1;
    while(low < high) {
        int lim = high - low;
        for(int i = 0; i < lim; ++i) {
            swap(A[low][low+i], A[low+i][high]);
            swap(A[high-i][low], A[low][low+i]);
            swap(A[high][high-i], A[high-i][low]);
        }
        low++;
        high--;
    }
}
```
