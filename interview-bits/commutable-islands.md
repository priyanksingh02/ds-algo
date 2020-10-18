```cpp
struct dset {
    vector<int> data;
    dset(int sz): data(vector<int> (sz+1, 0)) {
        for(int i = 0; i < data.size(); ++i) {
            data[i] = i;
        }
    }
    
    int parent(int x) {
        if(x == data[x]) 
            return x;
        else
            return data[x] = parent(data[x]);
    }
    
    void merge(int a, int b) {
        int pa = parent(a);
        int pb = parent(b);
        if(pa == pb)    
            return;
        data[pa] = pb;
    }
};

int Solution::solve(int A, vector<vector<int> > &B) {
    int ans = 0;
    dset ds(A);
    sort(B.begin(), B.end(), [](vector<int> &a, vector<int>&b) {
        return a[2] < b[2];
    });
    int count = 0;
    for(int i = 0; i < B.size(); ++i) {
        if(ds.parent(B[i][0]) != ds.parent(B[i][1])) {
            ans += B[i][2];
            ds.merge(B[i][0],B[i][1]);
            if(++count == A - 1)
                break;
        }
    }
    return ans;
}
```

```cpp
#include <numeric>
struct dset {
    vector<int> v;
    dset(int sz): v{vector<int> (sz+1, 0)} {
        iota(v.begin(), v.end(), 0);
    }
    int find(int i) {
        if(v[i] == i)
            return i;
        else
            return v[i] = find(v[i]);
    }
    
    bool merge(int i, int j) {
        int a = find(i);
        int b = find(j);
        if(a == b)
            return false;
        v[a] = b;
        return true;
    }
};

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(),[](const vector<int> & a, const vector<int> &b){
        return a[2] < b[2];
    });
    dset ds(A);
    int ans = 0;
    int cnt = 1;
    for(auto & x: B) {
        if(ds.merge(x[0], x[1])) {
            ans += x[2];
            if(++cnt == A)
                break;
        }
    }
    return ans;
}

```
