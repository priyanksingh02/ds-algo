#include<algorithm>
#include<vector>
#include<iostream>
#include"header.h"
using namespace std;

int main() {
    vector<int> numbers;
    generate_n(back_inserter(numbers), 10, addon::rn(1,39));
    debug() << imie(numbers);
    vector<int>  sorted_numbers {numbers};
    sort(begin(sorted_numbers),end(sorted_numbers));
    debug() << imie(sorted_numbers);
    vector<int> reverse_numbers {numbers};
    sort(reverse_numbers.rbegin(),reverse_numbers.rend());
    debug() << imie(reverse_numbers);
}
