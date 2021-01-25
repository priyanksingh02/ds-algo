#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> subset;
int n;

void search(int k ) {
    if (k == n+1) {
        cout << "{ ";
        for(auto x: subset) {
            cout << x << " ";
        }
        cout << "}\n";
    }
    else {
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
        search(k+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    search(0);
}

