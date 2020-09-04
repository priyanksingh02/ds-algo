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
