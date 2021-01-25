#include <iostream>
#include <cassert>
using namespace std;

inline int r(int a, int b) { return rand() %(b - a + 1) + a;}

int main() {
    for(int rep = 1; true; ++rep) {
        cout << "#" << rep << " [ ";
        //input - can be generated randomly using rand()
        int a = 10, b = 100;
        //function to check
        int n = r(a,b);
        cout << n << " ] " << endl;
        //test using assert
        assert(n <= b and n >= a);
        //if wrong, execution stops and prints counter example
    }
}
