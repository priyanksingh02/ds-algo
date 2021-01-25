#include <iostream>
#include <algorithm>
#include <vector>
#include "header.h"
using namespace std;

void merge(vector<int> & numbers, int l, int m, int n) {
    int n1 = m - l + 1;
    int n2 = n - m;
    vector<int> left (n1+1);
    vector<int> right (n2+1);
    for(int i = 0; i < n1; ++i)
        left[i] = numbers[l+i];
    for(int i = 0; i < n2; ++i)
        right[i] = numbers[m+1+i];
    left[n1]=right[n2] = 1e6;
    int i=0,j=0;
    for(int k = l; k <= n; ++k)
        numbers[k] = (left[i] <= right[j])?left[i++]:right[j++];
}

void merge_sort(vector<int> & numbers, int l, int n) {
    if (l < n) {
        int m = l + (n-l>>1);
        merge_sort(numbers, l, m);
        merge_sort(numbers, m+1, n);
        merge(numbers, l, m, n);
    }
}

int main() {
    vector<int> numbers;
    generate_n(back_inserter(numbers), 10, addon::rn(1, 49));
    debug() << imie(numbers);
    merge_sort(numbers, 0, numbers.size()-1);
    debug() << imie(numbers);
}
