```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int &x: nums) cin >> x;
  const int MAX = 100;
  vector<int> freq(MAX, 0);
  for(int x: nums) freq[x]++;
  sort(nums.begin(), nums.end(), [&](int a, int b) {
    return freq[a] > freq[b] or (freq[a] == freq[b] && a < b);
  });
  for(int x: nums) cout << x << ' ';
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
```
