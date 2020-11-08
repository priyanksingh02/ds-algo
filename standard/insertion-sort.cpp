#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> & arr) {
  for(int i = 1; i< (int)arr.size(); ++i) {
    int j = i;
    int tmp = arr[j];
    while(j > 0 && arr[j-1] > tmp) {
      arr[j] = arr[j-1];
      --j;
    }
    arr[j] = tmp;
  }
}

void print(vector<int> & arr) {
  for(auto & x: arr)
    cout << x << " ";
  cout << endl;
}

int main() {
  vector<int> arr {8, 4, 7, 2, 8, -40, 69, -34, 55};
  print(arr);
  insertion_sort(arr);
  print(arr);
}
