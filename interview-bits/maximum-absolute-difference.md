```cpp

int Solution::maxArr(vector<int> &A) {
    vector<int> plus, minus;
    for(int i = 0; i < A.size(); ++i) {
        plus.push_back(A[i]+i);
        minus.push_back(A[i]-i);
    }
    int maxplus = *max_element(plus.begin(), plus.end());
    int maxminus = *max_element(minus.begin(), minus.end());
    int minplus = *min_element(plus.begin(), plus.end());
    int minminus = *min_element(minus.begin(), minus.end());
    return max(maxplus-minplus, maxminus-minminus);
}
```
