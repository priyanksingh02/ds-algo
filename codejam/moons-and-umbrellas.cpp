#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y;
  string input;
  cin >> x >> y >> input;
  int cost = 0;
  int prev = -1;
  for(int i = 0; i < (int)input.size(); ++i) {
    if(input[i] == '?')
      continue;
    if(prev != -1 && input[i] != input[prev]) {
      switch(input[prev]) {
        case 'C':
          cost += x;
          break;
        case 'J':
          cost += y;
          break;
        default:
          assert(false);
      }
    }
    prev = i;
  }
  printf("%d\n",cost);
}

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i) {
    printf("Case #%d: ",i);
    solve();
  }
}
