#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> permutation (n,0);
    iota(permutation.begin(),permutation.end(),1);

    do {
        for(auto x: permutation) {
            cout << x << " ";
        }
        cout << "\n";
    }while(next_permutation(permutation.begin(), permutation.end()));

}

