## Basic Calculator II
```cpp
class Solution {
public:
    int precedence(char c) {
        if(c == '+' or c == '-')
            return 1;
        if(c == '*' or c == '/')
            return 2;
        assert(false); // something is wrong
        return 0;
    }
    
    int eval(int a , int b, char c) {
        switch(c) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': 
                assert(b != 0);
                return a/b;
            default:
                assert(false);
                return 0;
        }
    }
    
    int calculate(string s) {
        stringstream ss{s};
        stack<int> operand;
        stack<char> sym;
        char c;
        int n;
        ss >> n;
        operand.push(n);
        while(ss >> c) {
            if(c == ' ')
                continue;
            if(sym.empty() or precedence(sym.top()) < precedence(c))
                sym.push(c);
            else {
                while(!sym.empty() and precedence(sym.top()) >= precedence(c)) {
                    int b = operand.top(); operand.pop();
                    int a = operand.top(); operand.pop();
                    operand.push(eval(a, b, sym.top()));
                    sym.pop();
                }
                sym.push(c);
            }
            ss >> n;
            operand.push(n);
        }
        while(!sym.empty()) {
            int b = operand.top(); operand.pop();
            int a = operand.top(); operand.pop();
            operand.push(eval(a,b, sym.top()));
            sym.pop();
        }
        assert(!operand.empty());
        return operand.top();
    }
};
```
