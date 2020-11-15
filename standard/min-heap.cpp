#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct min_heap {
  vector<int> d;
  min_heap() {}
  min_heap(const vector<int> & arr) {
    d = arr;
    for(int i = parent((int)arr.size()-1); i>= 0; --i) {
      heapify(i);
    }
  }
  inline int parent(int a) { return (a-1)>>1;}
  inline int left(int a) { return a<<1;}
  inline int right(int a) { return left(a) + 1;}
  inline bool empty() { return d.empty(); }
  inline int size() { return d.size(); }

  void heapify(int i) {
    int l = left(i);
    int r = l+1;
    int min_elem = i;
    if(l < (int)d.size() && d[l] < d[min_elem])
      min_elem = l;
    if(r < (int)d.size() && d[r] < d[min_elem])
      min_elem = r;
    if(min_elem != i) {
      swap(d[min_elem], d[i]);
      heapify(min_elem);
    }
  }

  int extract_min() {
    if(d.empty())
      return -1;
    int min_elem = d.front();
    swap(d.front(), d.back());
    d.pop_back();
    if(!d.empty())
      heapify(0);
    return min_elem;
  }

  void insert(int val) {
    d.push_back(val);
    push_up((int)d.size() - 1);
  }

  void push_up(int pos) {
    int p = parent(pos);
    while(pos != p && d[p] > d[pos]) {
      swap(d[p], d[pos]);
      pos = p;
      p = parent(pos);
    }
  }

};

int main() {
  vector<int> arr { 3 , 5, 8, 2, 0, 5, 9, 1, 4, 6};
  min_heap mh {arr};
  while(!mh.empty())
    cout << mh.extract_min() << " ";
  cout << endl;
  mh.insert(5);
  mh.insert(15);
  mh.insert(4);
  mh.insert(1);
  mh.insert(0);
  while(!mh.empty())
    cout << mh.extract_min() << " ";
  cout << endl;
}
