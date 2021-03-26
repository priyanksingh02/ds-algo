#include <bits/stdc++.h>
using namespace std;

void print(vector<int> & arr) {
  for(int x: arr) {
    printf("%d ", x);
  }
  printf("\n");
}

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> arr(n);
  for(int i= 1; i <= n; ++i) {
    arr[i-1] = i;
  } 
  //cout << n << ":" << c << ": ";
  //print(arr);
  int cost = c - n + 1;
  int step = 2;
  int i = n - 2;
  while(i >= 0 && cost > 0) {
    ++cost;
    //cout << cost << "->" << step << ": ";
    if(cost >= step) {
      cost -= step;
      reverse(arr.begin() + i, arr.end());
    }
    else {
      reverse(arr.begin() + i, arr.begin() + i + cost);
      cost = 0;
    }
    //print(arr);
    step++;
    --i;
  }
  if(cost != 0)
    printf("IMPOSSIBLE\n");
  else {
    print(arr);
  }
}

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i) {
    printf("Case #%d: ",i);
    solve();
  }
}
