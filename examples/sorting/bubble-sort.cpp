
#include <bits/stdc++.h>
#include "header.h"
using namespace std;
typedef long long ll;

void sort(vector<int>& numbers) {
    //decreasing order
    for(int i = 1; i < numbers.size(); ++i) {
        for(int j = 1; j < numbers.size(); ++j) {
            if(numbers[j-1] < numbers[j]) {
                swap(numbers[j-1],numbers[j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> numbers;
    int n;
    cin >> n;
    generate_n(back_inserter(numbers), n, addon::rn(-n,n));
    debug() << imie(numbers);
    sort(numbers);
    debug() << imie(numbers);
}

