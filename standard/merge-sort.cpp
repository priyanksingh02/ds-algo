#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> & arr, int low , int mid, int high) {
  int lsize = mid - low + 1;
  int rsize = high - mid;
  vector<int> l(lsize), r(rsize);
  for(int i = 0; i < lsize; ++i)
    l[i] = arr[low+i];
  for(int i = 0; i < rsize; ++i)
    r[i] = arr[mid+1+i];
  l.push_back(INT_MAX);
  r.push_back(INT_MAX);
  int i = 0, j = 0;
  for(int k = low; k <= high; ++k) {
    arr[k] = (l[i] <= r[j])?l[i++]:r[j++];
  }
}

void merge_sort(vector<int>& arr, int low, int high) {
  if(low < high) {
    int mid = low + (high - low)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
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
  merge_sort(arr, 0, (int)arr.size()-1);
  print(arr);
}
