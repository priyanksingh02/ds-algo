#include <iostream>
#include <vector>
#include <algorithm>
#include "header.h"
using namespace std;

int main() {
    int n = 10;
    vector<int> numbers;
    generate_n(back_inserter(numbers), n, addon::rn(1, 5));
    debug() << imie(numbers);
    //remove duplicates
    sort(begin(numbers), end(numbers));
    numbers.erase(unique(begin(numbers), end(numbers)), end(numbers));
    debug() << imie(numbers);
}
