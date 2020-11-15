#include <bits/stdc++.h>
using namespace std;

int subarray_sum_k(vector<int> & arr, int k) {
  int n = arr.size();
  int count = 0;
  int prefix = 0;
  unordered_map<int, int> m;
  m[0] = 1;
  for(int i = 0;i < n; ++i) {
    prefix += arr[i];
    if(m.count(prefix-k)) {
      count += m[prefix-k];
    }
    m[prefix]++;
  }
  return count;
}

int main() {
  vector<int> arr = { 5, 2, 8, -1, 6, 1, 3, 4, 4, 6};
  cout << subarray_sum_k(arr, 7) << endl;
}
