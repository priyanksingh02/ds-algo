#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct union_find {
    vector<int> link, size;

    union_find(int n) {
        for(int i = 0; i <= n; ++i) {
            link.push_back(i);
            size.push_back(1);
        }
    }

    //find without path compression
    int find(int x) {
        while(x != link[x])
            x = link[x];
        return x;
    }

    //check same
    bool same(int a, int b) {
        return find(a) == find(b);
    }

    //join
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(size[a] < size[b])
            swap(a,b);
        size[a] += size[b];
        link[b] = a;
    }

    //find with path compression
    int find_pc(int x) {
        if(x == link[x])
            return x;
        return link[x] = find_pc(link[x]);
    }
};

int main() {
    union_find u(4);
    u.unite(3,2);
    u.unite(1,2);
    u.unite(0,1);
    cout << u.find(0) << endl;
    cout << u.find(4) << endl;
    cout << u.find(3) << endl;
    cout << u.find(1) << endl;
}

