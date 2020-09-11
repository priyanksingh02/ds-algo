```cpp
vector<int> Solution::solve(vector<int> &A) {
    int pos = lower_bound(A.begin(), A.end(), 0) - A.begin();
    int i = pos;
    int j = pos - 1;
    vector<int> ans;
    while(j >= 0 && i < A.size()) {
        if(abs(A[j]) <= A[i]) {
            ans.push_back(A[j]*A[j]);
            j--;
        }
        else {
            ans.push_back(A[i]*A[i]);
            i++;
        }
    }
    while(j >= 0) {
        ans.push_back(A[j]*A[j]);
        --j;
    }
    while(i < A.size()) {
        ans.push_back(A[i]*A[i]);
        ++i;
    }
    return ans;
}
```
