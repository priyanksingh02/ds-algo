#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> permutation;
int n;
bool chosen[10000+1] = {false};
void print() {
    for (auto x: permutation) {
        cout << x << " ";
    }
    cout << "\n";
}
void search() {
    if(n == permutation.size()) {
        print();
    }
    else {
        for(int i = 1; i <= n; ++i) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(chosen, 0 , sizeof(chosen));
    cin >> n;
    search();


}

