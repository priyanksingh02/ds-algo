#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n = 3;
    vector<int> coins (n, 0);
    coins[0] = 1;
    coins[1] = 3;
    coins[2] = 4;

    const int INF = (1<<30);
    int xlimit = 10;
    vector<int> values( xlimit + 1, 0);

    values[0]=0;
    for(int x = 1; x <= xlimit; ++x) {
        values[x] = INF;
        for(auto c: coins) {
            if(x-c >=0) {
                values[x] = min(values[x], values[x-c]+1);
            }
        }
    }
    cout << values[xlimit] << endl;
}
