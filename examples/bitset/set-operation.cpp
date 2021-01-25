// for numbers less than 32
// union : x | y
// intersection : x & y
// complement : ~x
// set-difference : x & ~y
// No of elements : __builtin_popcount()
#include <iostream>
using namespace std;
int no_of_elements(int x) {
    return __builtin_popcount(x);
}
void print(int x) {
    for(int i = 0; i < 32; ++i) {
        if(x & (1<<i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main() {
    int x = 0; // {1,3,4,8}
    x |= (1<<1);
    x |= (1<<3);
    x |= (1<<4);
    x |= (1<<8);
    //oneliner
    //x = (1<<1) | (1<<3) | (1<<4) | (1<<8);
    // y = {3,6,8,9}
    int y = (1<<3) | (1<<6) | (1<<8) | (1<<9);
    //union = {1,3,4,6,8,9}
    int result = x | y;
    cout << no_of_elements(result) << endl;
    print(result);
}
