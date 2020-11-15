#include<iostream>
using namespace std;

void print() {
  cout << endl;
}

template <typename T, typename... TAIL>
void print(T item, TAIL... tail) {
  cout << item << " ";
  print(tail...);
}

int main() {
  print("hello","world",1,2,3);
}
