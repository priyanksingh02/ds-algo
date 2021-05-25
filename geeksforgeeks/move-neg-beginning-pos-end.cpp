// Both solution used for partition in Quick Sort
#include <bits/stdc++.h>
using namespace std;

// Constant Extra Space
void arrange(int arr[], int n) {
  int pivot = 0;
  for(int i = 0; i < n; ++i) {
    if(arr[i] < 0) {
      swap(arr[i], arr[pivot++]);
    }
  }
}

//two pointer approach
void arrange2(int arr[], int n) {
  int neg = 0, pos = n-1;
  while(neg < pos) {
    if(arr[neg] < 0) {
      neg++;
      continue;
    }
    if(arr[pos] >= 0) {
      pos--;
      continue;
    }
    swap(arr[neg],arr[pos]);
    neg++;
    pos--;
  }
}

int main() {
  int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
  int n = sizeof(arr)/sizeof(int);
  arrange2(arr, n);
  for(int i = 0;i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
