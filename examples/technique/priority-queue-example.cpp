#include <iostream>
#include <queue>
using namespace std;

int main() {
    // default: max heap
    priority_queue<int> pq;
    // min heap
    // priority_queue<int, vector<int>, greater<int>> q;
    pq.push(3);
    pq.push(6);
    pq.push(4);
    pq.push(1);
    // max element
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();

}
