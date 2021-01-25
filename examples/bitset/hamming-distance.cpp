// hamming distance is the number of positions where the bit
// string differs.
//      hamming(01101,11001) = 2

// Minimum Hamminmg Distance: For k strings, the minimum hamming
// distance between two strings
// Answer for [00111, 01101, 11110] is 2
//
//      hamming(00111, 01101) = 2,
//      hamming(00111, 11110) = 3,
//      hamming(01101, 11110) = 3
#include <iostream>
#include <string>
using namespace std;

// naive approach O(n^2*k)
int hamming_naive(string &a, string &b) {
    int d= 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i])
            ++d;
    }
    return d;
}

// for k  <= 32; use int
// O(1)
int hamming(int a, int b) {
    return __builtin_popcount(a^b);
}

int main() {
    // from example; answer = 2;
    cout << hamming(0x7,0xd) << endl;
}
