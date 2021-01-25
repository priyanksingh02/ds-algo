#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(5);
    cout << s.size() << endl; //4
    s.erase(3); // erases all occurance of 3
    cout << s.size() << endl; // 1
    s.insert(3);
    s.insert(3);
    // count is not efficient for multiset
    cout << s.count(3) << endl; //2
    //to erase one occurance
    s.erase(s.find(3)); //delete 1st occurance
    cout << s.count(3) << endl; //1
    //print
    for(auto x: s)
        cout << x << " ";
    cout << endl;

}
