```cpp
class MinStack {
    stack<int> data;
    stack<int> m; // minimum
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(m.empty() or m.top() >= x)
            m.push(x);
        data.push(x);
    }
    
    void pop() {
        if(data.empty())
            return;
        if(m.top() == data.top())
            m.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 ```
