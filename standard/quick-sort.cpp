#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> & arr, int low, int high) {
  int pivot = low;
  for(int i = low; i < high; ++i) {
    if(arr[i] < arr[high]) {
      swap(arr[i], arr[pivot++]);
    }
  }
  swap(arr[pivot], arr[high]);
  return pivot;
}

void quick_sort(vector<int> & arr, int low, int high) {
  if(low < high) {
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot-1);
    quick_sort(arr, pivot+1, high);
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
  quick_sort(arr, 0, (int)arr.size()-1);
  print(arr);
}
