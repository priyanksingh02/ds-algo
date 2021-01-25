#include <iostream>
#include <vector>
#include <algorithm>
#include "header.h"
using namespace std;

bool search(vector<int> & numbers , int key) {
    int pos = 0;
    int n = numbers.size();
    for (int jump = n/2; jump >= 1; jump >>= 1) {
        while(pos + jump < n and numbers[pos + jump] <= key)
            pos += jump;
    }
    if(numbers[pos] == key)
        return true;
    else
        return false;
}

string out(bool result) {
    return (result)?"Found":"Not Found";
}

int main() {
    int n = 10;
    vector<int> numbers (n, 0);
    generate(begin(numbers), end(numbers), addon::rn(1,20));
    sort(begin(numbers), end(numbers));
    debug() << imie(numbers);
    cout << "find " << 5 << " : " << out(search(numbers, 5)) << endl;
    cout << "find " << 1 << " : " << out(search(numbers, 1)) << endl;
    cout << "find " << 9 << " : " << out(search(numbers, 9)) << endl;
}
