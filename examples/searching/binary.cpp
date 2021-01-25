#include <iostream>
#include <vector>
#include <algorithm>
#include "header.h"
using namespace std;

bool search (const vector<int> & numbers, int key) {
    int first = 0;
    int last = numbers.size() - 1;
    while(first <= last) {
        int mid = first + (last - first >> 1);
        if (numbers[mid] == key)
            return true;
        else if(numbers[mid] < key)
            first = mid + 1;
        else
            last = mid -1;
    }
    return false;
}

string out(bool result) {
    return (result)?"Found":"Not Found";
}

int main() {
    int n = 10;
    vector<int> numbers (n, 0);
    generate(begin(numbers), end(numbers), addon::rn(1,n));
    sort(begin(numbers), end(numbers));
    debug() << imie(numbers);
    cout << "find " << 5 << " : " << out(search(numbers, 5)) << endl;
    cout << "find " << 1 << " : " << out(search(numbers, 1)) << endl;
    cout << "find " << 9 << " : " << out(search(numbers, 9)) << endl;
}
