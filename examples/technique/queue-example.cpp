#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(4);
    q.push(5);
    cout << q.front() << endl;//4
    cout << q.back() << endl; //5
    q.pop();
    cout << q.empty() << endl; //0
}
