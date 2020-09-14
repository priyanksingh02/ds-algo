O(nlogn) : Using segment tree
```cpp
// similar to range sum segment tree
// Tells Number of position vacant in a given range
struct seg_tree {
    vector<int> data;
    int n;
    seg_tree(int sz) {
        n = sz;
        int x = ceil(log2(sz));
        int tree_size = 2 * pow(2, x) - 1;
        data.resize(tree_size);
        construct(0, 0, n - 1);
    }
    int construct(int k, int low, int high) {
        if(low == high) {
            data[k] = 1;
        }
        else {
            int mid = get_mid(low, high);
            data[k] = construct(left(k), low, mid) +
            construct(right(k), mid+1, high);
        }
        return data[k];
    }
    
    int left(int i) { return i*2 + 1; }
    int right(int i) { return i*2 + 2; }
    int get_mid(int i, int j) { return i + (j-i >> 1);}
    
    int get_count(int i, int j) {
        if(i < 0 || j >= n || i > j)
            return -1;
        return get_count_rec(0, 0, n - 1, i, j);
    }
    
    int get_count_rec(int k, int low, int high, int i, int j) {
        if(i <= low && j >= high)
            return data[k];
        else if(i > high || j < low)
            return 0;
        else {
            int mid = get_mid(low, high);
            return get_count_rec(left(k), low, mid, i, j) + 
                get_count_rec(right(k), mid+1,high, i, j);
        }
    }
    
    // binary search to find position index
    int get_pos(int pos) {
        int low = 0;
        int high = n - 1;
        while(low < high) {
            int mid = low + (high - low >> 1);
            int c = get_count(low, mid);
            if(c >= pos) {
                high = mid;
            }
            else {
                low = mid + 1;
                pos -= c; // update target
            }
        }
        return low;
    }
    
    void remove_rec(int k, int low, int high, int pos) {
        if(pos < low || pos > high)
            return;
        data[k]--;
        if(low != high) {
            int mid = get_mid(low, high);
            remove_rec(left(k), low, mid, pos);
            remove_rec(right(k), mid+1, high, pos);
        }
    }
    
    void remove(int pos) {
        assert(pos >= 0 && pos < n);
        remove_rec(0, 0, n-1, pos);
    }
    
    void print() {
        cout << "Tree: ";
        for(auto &x: data) {
            cout << x<< " ";
        }
        cout << endl;
    }
};


vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int> idx(n);
    for(int i = 0;i < n; ++i)
        idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j) {return A[i] < A[j];});
    seg_tree st(n);
    // st.print();
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) {
        int pos = st.get_pos(B[idx[i]]+1);
        assert(pos >= 0 && pos < n);
        ans[pos] = A[idx[i]];
        st.remove(pos);
    }
    return ans;
    
}

```

O(n^2) : Mostly give TLE
```cpp

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> h (A.size());
    int n= A.size();
    for(int i =0 ;i < n; ++i) {
        h[i].first = A[i];
        h[i].second = B[i];
    }
    sort(h.begin(), h.end());
    vector<int> ans (n, -1);
    for(int i = 0; i < n; ++i) {
        int k = 0;
        int j = 0;
        while(ans[j] != -1)
            ++j;
        while(k < h[i].second) {
            if(ans[j] == -1)
                ++k;
            ++j;
        }
        while(ans[j] != -1)
            ++j;
        ans[j] = h[i].first;
    }
    return ans;
}
```
