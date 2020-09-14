#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

struct seg_tree {
    vector<int> arr;
    vector<int> data;
    int n;

    seg_tree(const vector<int> & v) {
        n = v.size();
        arr = v;
        int x = ceil(log2(n));
        int sz = 2*pow(2, x) - 1;
        data.resize(sz, 0);
        construct(0, 0, n - 1);
    }

    int left ( int i ) { return i*2 + 1; }
    int right (int i ) { return i*2 + 2; }

    int construct(int k, int low, int high) {
        if(low == high) {
            data[k] = arr[low];
        }
        else {
            int mid = low + (high - low)/2;
            data[k] = construct(left(k), low , mid) + construct(right(k), mid+1, high);
        }
        return data[k];
    }

    void print() {
        cout << "Seg Tree: ";
        for(auto &x: data) {
            cout << x << " ";
        }
        cout << endl;
    }

    int get_sum(int i, int j) {
        if(i < 0 || j >= n || i > j)
            return -1;
        return sum(0, 0, n-1, i, j);
    }

    int sum(int k, int low, int high, int i, int j) {
        if(i <= low && j >= high)
            return data[k];
        else if(i > high || j < low)
            return 0;
        else {
            int mid = low + (high - low)/2;
            return sum(left(k), low, mid, i, j) + sum(right(k), mid+1, high,i, j);
        }
    }

    void update(int i, int new_val) {
        if(i < 0 || i >= n)
            return ;
        int dif = new_val - arr[i];
        arr[i] = new_val;
        update(0, 0, n - 1, i, dif);
    }

    void update(int k, int low, int high, int i, int dif) {
        if(i < low || i > high)
            return ;
        data[k] += dif;
        if(low != high) {
            int mid = low + (high - low)/2;
            update(left(k), low, mid, i, dif);
            update(right(k), mid+1, high, i, dif);
        }
    }
};

int main() {
    vector<int> arr = { 1, 5, 2, 7, 6, 3, 9 };
    seg_tree st(arr);
    st.print();
    assert(st.get_sum(1,3) == 14);
    assert(st.get_sum(0,5) == 24);
    assert(st.get_sum(4,6) == 18);
    st.update(0, 10);
    assert(st.get_sum(0,1) == 15);
    assert(st.get_sum(1,2) == 7);
    assert(st.get_sum(4,6) == 18);
}
