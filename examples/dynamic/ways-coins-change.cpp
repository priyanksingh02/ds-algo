// No of ways the coin sum can be created using coins;
// consider coins = {1, 3, 4}
// then 5 can be created in 6 ways
// 1. 1+1+1+1+1+1
// 2. 1+1+3
// 3. 1+3+1
// 4. 3+1+1
// 5. 1+4
// 6. 4+1
// recursive formula: solve(n)= solve(n-1) + solve(n-3) + solve(n-4)
// complete formula: n = 0 if neg; 1 if 0; formula for others
//
#include <iostream>
#include <vector>
using namespace std;

//solution could be too large
// use mod 10^9 + 7
const int m = 1e9+7;

int main() {
    int n = 5;
    vector<int> coins = { 1, 3, 4};
    vector<int> values (n+1, 0);

    values[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for(auto c: coins) {
            if(i-c >= 0) {
                values[i] += values[i-c];
                values[i] %= m;
            }
        }
    }
    cout << values[n] << endl;
}
