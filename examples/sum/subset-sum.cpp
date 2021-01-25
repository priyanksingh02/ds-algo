#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum  = 0, best = 0;
    vector<int> numbers = {-1, 2, 4, -3, 5, 2, -5, 2};
    // answer = 10
    for(int x : numbers) {
        sum = max(sum + x, x);
        best = max(best, sum);
    }
    cout << best << endl;
}
