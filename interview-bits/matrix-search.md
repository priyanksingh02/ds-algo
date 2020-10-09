```cpp

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    if(A.empty() or A.front().empty())
        return false;
    vector<int> col;
    for(int i = 0; i < A.size(); ++i) {
        col.push_back(A[i].front());
    }
    int row = upper_bound(col.begin(), col.end(), B) - col.begin();
    if(row == 0)
        return false;
    return binary_search(A[row-1].begin(), A[row-1].end(), B);
}
```
