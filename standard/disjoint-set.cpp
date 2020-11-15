#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dset {
  vector<int> parent;
  vector<int> rank;

  dset(int sz): parent {vector<int> (sz+1, -1)}, rank {vector<int> (sz+1, 0)} {}
  int find(int a) {
    if(parent[a] < 0)
      return a;
    else
      return parent[a] = find(parent[a]);
  }

  bool merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa == pb)
      return false;
    if(rank[pa] < rank[pb]) {
      parent[pb] += parent[pa]; // update size of parent
      parent[pa] = pb;
    } else if(rank[pa] > rank[pb]) {
      parent[pa] += parent[pb];
      parent[pb] = pa;
    }
    else {
      parent[pb] += parent[pa];
      parent[pa] = pb;
      rank[pb]++;
    }
    return true;
  }

  void print() {
    for(int i = 0; i < (int)parent.size(); ++i) {
      cout << i << ": " << parent[i] << " " << rank[i] << endl;
    }
  }

  int set_size(int a) {
    return abs(parent[find(a)]);
  }

};

int main() {
  dset d(5);
  d.merge(1, 2);
  d.merge(3, 4);
  d.merge(2, 5);
  d.merge(4, 5);
  d.print();
  cout << endl;
  cout << d.set_size(3) << endl; 
  cout << endl;
  d.print();
}
