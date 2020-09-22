```cpp

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans;
    int i = 1;
    int j = B;
    for(int k = 0; k < A.size(); ++k) {
        if(A[k] == 'I')
            ans.push_back(i++);
        else
            ans.push_back(j--);
    }
    ans.push_back(j);
    return ans;
}
```
