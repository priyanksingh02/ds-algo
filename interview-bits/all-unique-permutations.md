```cpp
bool per(vector<int> & a) {
    if(a.size() < 2)
        return false;
    int i = (int)a.size() - 2;
    while(i >= 0) {
        if(a[i] < a[i+1]) {
            int j = (int)a.size() - 1;
            while(j > i && a[j] <= a[i])
                --j;
            swap(a[i],a[j]);
            reverse(a.begin()+i+1, a.end());
            return true;
        }
        --i;
    }
    return false;
}

vector<vector<int> > Solution::permute(vector<int> &a) {
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    do {
        ans.push_back(a);
    }while(per(a));
    return ans;
}

```
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

