#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dset {
  vector<int> parent;
  vector<int> rank;
  dset(int s): parent{ vector<int> (s +1, -1)}, rank{vector<int> (s+1, 0)} {}
  int find(int a) {
    if(parent[a] < 0) return a;
    else return parent[a] = find(parent[a]);
  }
  bool merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa == pb)
      return false;
    if(rank[pa] > rank[pb])
      parent[pb] = pa;
    else if(rank[pa] < rank[pb])
      parent[pa] = pb;
    else {
      parent[pb] = pa;
      rank[pa]++;
    }
    return true;
  }
};

vector<vector<int>> kruskal(vector<vector<int>> & edges, int V) {
  dset d(V);
  vector<vector<int>> ans;
  sort(edges.begin(), edges.end(), [](const vector<int> & a, const vector<int> & b) {
        return a[2] < b[2];
      });
  for(auto & e: edges) {
    if(d.merge(e[0], e[1])) {
      ans.push_back(e);
    }
  }
  return ans;
}

int main() {
  int V = 8;
  vector<vector<int>> edges {
    {0, 7, 8}, {0, 1, 4}, {1, 7, 11}, {1, 2, 8}, {7, 6, 1}, {7, 8, 7}, {6, 8, 6}, {2, 8, 2},
    {2, 3, 7}, {2, 5, 4}, {5, 6, 2}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}
  };
  // Answer = 6-7, 2-8, 5-6, 0-1, 2-5, 2-3, 0-7, 3-4
  // Weight of MST = 37
  int weight = 0;
  for(auto & v: kruskal(edges, V)) {
    weight+= v[2];
    cout << v[0] << "-" << v[1] << ", ";
  }
  cout << endl;
  cout << weight << endl;
}
