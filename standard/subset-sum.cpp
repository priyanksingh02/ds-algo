#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {
  // Input
  vector<int> arr { 6, 3, 5, 8, 2};


  // Main Logic
  long sum = accumulate(arr.begin(), arr.end(), 0l);
  vector<bool> dp(sum+1, false);
  dp[0] = true;
  for(int i = 0; i < (int)arr.size(); ++i) {
    for(int j = 0; j <= sum; ++j) {
      if(dp[j] and j + arr[i] <= sum) {
        dp[j + arr[i]] = true;
      }
    }
  }
  
  // Output
  cout << "Array :";
  for(int i = 0; i < (int)arr.size(); ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
  cout << "Sums Possible : ";
  for(int i = 0; i < (int)dp.size(); ++i) {
    if(dp[i])
      cout << i << " ";
  }
  cout << endl;
}
