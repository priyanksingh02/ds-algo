```cpp

stack<int> d;
stack<int> m;
MinStack::MinStack() {
   while(!d.empty()) d.pop();
   while(!m.empty()) m.pop();
}

void MinStack::push(int x) {
    if(m.empty() or m.top() >= x) {
        m.push(x);
    }
    d.push(x);
}

void MinStack::pop() {
    if(d.empty())
        return ;
    if(m.top() == d.top())
        m.pop();
    d.pop();
}

int MinStack::top() {
    if(d.empty()) return -1;
    return d.top();
}

int MinStack::getMin() {
    if(m.empty()) return -1;
    return m.top();
}

```
