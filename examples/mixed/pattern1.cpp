// given n
// if odd: multiply by 3 and add 1
// if even: divide by 2
// stop at 1
// Task: print pattern
# include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if(n%2 == 0) {
            n >>= 1;
        }
        else {
            n = n*3+1;
        }
    }
    cout << n << endl;
}
