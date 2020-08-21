```cpp

// example: 2 4 3 1 -> 3 1 2 4
    // steps: 
    // starting from 1 , find val > 2 ; i,e 3 in this case
    // swap(2, 3) : becomes 3 4 2 1
    // reverse after 3 :(4 2 1) -> 1 2 4
    // result: 3 1 2 4
bool next_permute(vector<int> & v) {
    int i;
    for(i = (int)v.size() - 2; i >= 0 ; --i) {
        if(v[i] < v[i+1]) {
            break;
        }
    }
    if(i == -1)
        return false;
    
    for(int j = v.size() - 1; j > i; --j) {
        if(v[j] > v[i]) {
            swap(v[i], v[j]);
            break;
        }
    }
    reverse(v.begin()+i+1, v.end());
    return true;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    do {
        ans.push_back(A);
    }while(next_permute(A));
    return ans;
}
```
