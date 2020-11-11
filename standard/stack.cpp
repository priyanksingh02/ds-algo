#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct stack_overflow {};
struct stack_underflow {};

struct stack {
  vector<int> data;
  int n;
  stack(int sz): n{sz} {}

  int size() { return data.size();}
  int empty() { return data.empty(); }

  int top() {
    if(data.empty())
      return -1;
    else
      return data.back();
  }

  void push(int val) {
    if(val == n) {
      throw stack_overflow();
    }
    data.push_back(val);
  }

  void pop() {
    if(data.empty())
      throw stack_underflow();
    data.pop_back();
  }
};

const int MAXSIZE = 1e4;
struct stack_arr {
  int data[MAXSIZE];
  int ptr_top = -1;

  int size() { return ptr_top+1;}
  int empty() { return ptr_top == -1; }
  int full() {return ptr_top + 1 == MAXSIZE; }

  int top() {
    if(empty())
      return -1;
    else
      return data[ptr_top];
  }

  void push(int val) {
    if(full())
      throw stack_overflow();
    data[++ptr_top] = val;
  }

  void pop() {
    if(empty())
      throw stack_underflow();
    --ptr_top;
  }
};



int main() {
  vector<int> input { 3, 5, 2, 6, 7 ,1 };
  stack st(15);
  stack_arr st_arr;
  for(int x: input) {
    st.push(x);
    st_arr.push(x);
  }
  while(!st.empty()) {
    assert(st.top() == st_arr.top());
    st.pop();
    st_arr.pop();
  }
  cout << "ALL OKAY!" << endl;
}
