#include <iostream>
#include <algorithm>
#include "header.h"
using namespace std;

int main() {

    int n = 10;
    int limit = 10;
    vector<int> numbers ;
    generate_n(back_inserter(numbers), n, addon::rn(1, limit));
    debug() << imie(numbers);

    vector<int> count (limit + 1, 0);
    vector<int> sorted (n, 0) ;
    for (int i = 0; i < numbers.size() ; ++i)
        count[numbers[i]]++;
    for (int i = 1; i < count.size(); ++i)
        count[i] += count[i-1];
    for (int i = 0; i < numbers.size() ; ++i) {
        sorted[count[numbers[i]]-1] = numbers[i];
        --count[numbers[i]];
    }
    debug() << imie(sorted);
}
