#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct deque_overflow {};
struct deque_underflow {};
struct deque_empty {}; 
const int MAXSIZE = 5;

struct deque {
  int data[MAXSIZE];
  int f, b; // front , back pointers;
  deque() : f{-1}, b{-1} {}

  bool empty() { return b == -1; }
  bool full() { return (b+1)%MAXSIZE == f; }
  int size() { 
    if(b >= f) {
      return b - f + 1; // back ptr is ahead of front ptr;
    }
    else {
      return b + 1 + (MAXSIZE - f); // (b + 1) -> front segment ; (max - f) -> back segment
    }
  }

  int front() {
    if(empty())
      throw deque_empty();
    return data[f];
  }

  int back() {
    if(empty())
      throw deque_empty();
    return data[b];
  }

  void push_back(int val) {
    if(full())
      throw deque_overflow();
    if(empty())
      f = b = 0;
    else
      b = (b+1)%MAXSIZE;
    data[b] = val;
  }

  void push_front(int val) {
    if(full())
      throw deque_overflow();
    if(empty())
      f = b = 0;
    else
      f = (f - 1 + MAXSIZE)%MAXSIZE;
    data[f] = val;
  }

  void pop_back() {
    if(empty())
      throw deque_underflow();
    if(f == b)
      f = b = -1;
    else
      b = (b-1+MAXSIZE)%MAXSIZE;
  }

  void pop_front() {
    if(empty())
      throw deque_underflow();
    if(f == b)
      f = b = -1;
    else
      f = (f+1)%MAXSIZE;
  }

  void print() {
    cout << "DATA: ";
    if(empty())
      return;
    if(f <= b) {
      for(int i = f; i <= b; ++i) {
        cout << data[i] << " ";
      }
    }
    else {
      for(int i = f; i < MAXSIZE; ++i) {
        cout << data[i] << " ";
      }
      for(int i = 0; i <= b; ++i) {
        cout << data[i] << " ";
      }
    }
    cout << endl;
  }

};

int main() {
  deque d;
  assert(d.empty());
  d.push_back(4);
  assert(!d.empty());
  d.pop_back();
  assert(d.empty());
  d.push_front(5);
  assert(!d.empty());
  d.pop_back();
  assert(d.empty());
  d.push_back(1);
  d.push_back(3);
  d.print();
  d.pop_front();
  assert(!d.empty());
  d.push_back(3);
  d.push_back(3);
  d.push_back(3);
  d.push_back(3);
  assert(d.full());
  d.print();
  d.pop_front();
  d.pop_back();
  d.push_back(5);
  d.push_front(1);
  assert(d.full());
  assert(!d.empty());
  assert(d.size() == 5);
  d.print();
  //d.push_back(4); // overflow
  cout << "ALL OKAY!" << endl;
}
