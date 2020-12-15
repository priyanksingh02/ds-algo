```cpp
#include <bits/stdc++.h>
using namespace std;

void flood(int r, int c, vector<vector<int>> & grid, int old, int color) {
  if(r < 0 or c < 0 or r >= grid.size() or c >= grid[r].size() or grid[r][c] != old)
    return;
  grid[r][c] = color;
  flood(r-1, c, grid, old, color);
  flood(r, c-1, grid, old, color);
  flood(r+1, c, grid, old, color);
  flood(r, c+1, grid, old, color);
}

void solve() {
  int m,n;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int> (n));
  for(auto & y: grid) 
    for(auto & x: y)
      cin >> x;
  int r, c, color;
  cin >> r >> c >> color;
  int old = grid[r][c];
  if(old != color)
    flood(r, c, grid, old, color);
  for(auto & y: grid)
    for(auto & x: y)
      cout << x << " ";
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
