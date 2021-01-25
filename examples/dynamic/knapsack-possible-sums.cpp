// Possible sums for weights
// w = {1, 3, 3, 5}
// total weight = 12 = m
// n = number of weights
// answer: all 0..12 are possible except 2 10
// recursive equation for possible sums
//
// possible(x, k) = possible(x - w[k], k-1) or possible(x, k-1)
// base case: possible(x, 0) = true if x == 0 else false
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> w = { 1, 3, 3, 5};
    int n = w.size();
    int m =accumulate(begin(w),end(w),0);

    bool possible[n+1][m+1] ;
    memset(possible, 0, sizeof possible);

    possible[0][0] = true;
    for(int k = 1; k <= n; ++k) {
        for(int x = 0; x <= m; ++x) {
            if(x-w[k-1] >= 0)
                possible[k][x] |= possible[k-1][x-w[k-1]];
            possible[k][x] |= possible[k-1][x];
        }
    }
    for(auto x: possible[n]) {
        cout << x << " ";
    }
    cout << endl;

}
