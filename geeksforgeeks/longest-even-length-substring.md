```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string input;
    cin >> input;
    int n = input.size();
    vector<int> prefix(n+1, 0);
    for(int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i-1] + input[i-1] - '0';
    }
    int ans  = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = i+1; j < n; j+=2) {
        int mid = (i + j)/2;
        if(prefix[mid+1] - prefix[i] == prefix[j+1] - prefix[mid+1])
          ans = max(ans, j-i+1);
      }
    }
    cout << ans << "\n";
  }
}

```
