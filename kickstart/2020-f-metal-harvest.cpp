#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,t;
  cin >> n >> t;
  vector<pair<int,int>> vals(n);
  for(auto & x: vals) cin >> x.first >> x.second;
  sort(vals.begin(), vals.end());
  int cur = 1;
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    if(vals[i].second <= cur)
      continue;
    if(vals[i].first > cur)
      cur = vals[i].first;
    int deployment = ceil(((double)vals[i].second - cur)/t);
    cur = cur + deployment*t;
    ans += deployment;
  }
  cout << ans << "\n";
}

int main() {
  int tlim;
  cin >> tlim;
  for(int i = 1; i <= tlim; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
