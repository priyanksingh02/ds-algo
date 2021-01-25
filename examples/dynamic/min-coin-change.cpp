#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int coins[1000010];
bool ready[1000010];
int value[1000010];
const int INF = 100000010;

int solve(int x) {
    if ( x < 0) return INF;
    if( x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INF;
    for(int i = 0; i < n; ++i) {
        best = min(best, solve(x - coins[i])+1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}

int main() {
    n = 3;
    coins[0] = 1;
    coins[1] = 3;
    coins[2] = 4;

    memset(ready, 0, sizeof(ready));
    memset(value, 0, sizeof(value));

    cout << solve(10) << endl; // 3
}
