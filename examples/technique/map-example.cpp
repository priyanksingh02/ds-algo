#include <iostream>
#include <map> // balanced binary tree O(log n)
#include <unordered_map> // hash map O(1)
using namespace std;

int main() {
    map<int, int> m;
    m[1] = 2;
    m[2] = 3;
    // no of elements
    cout << m.size() << endl;
    // access element
    cout << m[3] << endl; // creats new element if absent
    // count checks if element exists
    if(m.count(2)) {
        cout << "found" << endl;
    }
    // print
    for (auto x: m) {
        cout << x.first << " " << x.second << endl;
    }
}

