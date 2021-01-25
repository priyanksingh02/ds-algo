#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int coins[100];
int first[1000010];
int values[100010];
const int INF = (1 << 30);
int no_coins;

void print_optimal(int n) {
    int i = n;
    while(i > 0) {
        cout << first[i] << " ";
        i -= first[i];
    }
    cout << endl;
}


void solve(int n) {
    memset(first, 0, sizeof(first));
    memset(values, 0, sizeof(values));
    values[0] = 0;
    for(int i = 1; i <= n; ++i) {
        values[i] = INF;
        for(int c = 0 ; c < no_coins; ++c) {
            int coin = coins[c];
            if(i - coin >= 0 and values[i-coin] + 1 < values[i]) {
                values[i] = values[i-coin] + 1;
                first[i] = coin;
            }
        }
    }
    cout << values[n] << endl;
    print_optimal(n);
}

int main() {
    no_coins = 3;
    coins[0] = 1;
    coins[1] = 3;
    coins[2] = 4;
    solve(10);
}
