#include <iostream>
#include <set> // balanced binary search tree
#include <unordered_set> // hash based implementation
using namespace std;

int main() {
    set<int> s; // contains unique elements
    s.insert(3);
    s.insert(4);
    s.insert(5);
    // count number of occurances of element
    cout << s.count(3) << endl; //1;
    s.erase(3);
    cout << s.count(3) << endl; //0;
    // printed in increasing order
    for (auto x: s) {
        cout << x << " ";
    }
    cout << endl;
    // No of elements
    cout << s.size() << endl;
    // find element
    auto iter = s.find(5) ;
    if (iter != s.end()) // true if found
        cout << "5 found!" << endl;
}
