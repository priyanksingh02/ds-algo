```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> k >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--) {
      int input;
      cin >> input;
      pq.push(input);
      if(pq.size() > k) {
        pq.pop();
      }
      if(pq.size() == k) cout << pq.top() << " ";
      else cout << "-1 ";
    }
    cout << "\n";
  }
}

```
