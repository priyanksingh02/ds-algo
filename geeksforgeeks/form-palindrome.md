```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(const string& input, int low, int high) {
    if(low >= high) {
        return 0;
    }
    if(dp[low][high] != -1)
        return dp[low][high];
    if(input[low] == input[high]) {
        dp[low][high] = solve(input, low+1, high-1);
    }
    else {
        dp[low][high] = min(solve(input, low+1, high), solve(input, low, high-1)) + 1;
    }
    return dp[low][high];
}

int main() {
   int t = 0;
   cin >> t;
   while(t--) {
        string input; 
        cin >> input;
        dp.clear();
        int n = input.size();
        dp.resize(n, vector<int> (n, -1));
        cout << solve(input, 0, (int)input.size() - 1) << "\n";
    }
}

```
