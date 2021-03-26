#include <bits/stdc++.h>
using namespace std;

//void print(vector<int> & arr) {
  //for(int i = 0; i < arr.size(); ++i) {
    //fprintf(stderr,"%d ",arr[i]);
  //}
  //fprintf(stderr,"\n");
//}


void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(auto &x : arr) cin>> x;
  vector<int> sorted_arr(arr);
  sort(sorted_arr.begin(), sorted_arr.end());
  //print(arr);
  //print(sorted_arr);
  int cost = 0;
  for(int i = 0; i + 1 < n; ++i) {
    auto iter = find(arr.begin() + i, arr.end(), sorted_arr[i]);
    assert(iter != arr.end());
    int cur_cost = (iter - arr.begin() - i + 1);
    //printf("cur_cost is %d\n",cur_cost);
    reverse(arr.begin() + i, iter + 1);
    cost += cur_cost;
    //print(arr);
  }
  printf("%d\n", cost);
}

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i) {
    printf("Case #%d: ",i);
    solve();
  }
}
