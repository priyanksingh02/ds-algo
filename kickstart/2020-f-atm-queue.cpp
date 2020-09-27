#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for(auto & x: arr) cin >> x;
  vector<pair<int,int>> pos;
  for(int i = 0; i < n; ++i) {
    pos.push_back({1+(arr[i]-1)/x, i});
  }
  sort(pos.begin(), pos.end());
  for(auto & x: pos) {
    cout << x.second + 1 << " ";
  }
  cout << "\n";
}

int main() {
  int tlim;
  cin >> tlim;
  for(int i = 1; i <= tlim; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
