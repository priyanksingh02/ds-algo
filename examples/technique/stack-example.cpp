#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(0);
    cout << s.top() << endl; // 0
    s.pop();
    cout << s.top() << endl; // 5
    s.pop();
    cout << s.top() << endl; // 2
    s.pop();
    cout << s.empty() << endl; // 1; true
}
