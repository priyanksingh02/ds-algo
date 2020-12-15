```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, n;
  cin >> n >> m;
  map<int,int> hash;
  int num;
  for(int i = 0; i < n; ++i) {
    cin >> num;
    hash[num]++;
  }
  for(int i = 0; i < m; ++i) {
    cin >> num;
    if(hash.count(num)) {
      for(int j = 0; j < hash[num]; ++j) {
        cout << num << " ";
      }
      hash.erase(num);
    }
  }
  for(auto& x: hash) {
    for(int j = 0; j < x.second; ++j) {
      cout << x.first << " ";
    }
  }
  cout << "\n";
  
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}

```
