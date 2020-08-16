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
