```cpp

string Solution::findDigitsInBinary(int A) {
    if(A == 0)
        return "0";
    stack<int> num;
    while(A) {
        num.push(A%2);
        A/=2;
    }
    string ans;
    while(!num.empty()) {
        ans.push_back('0'+num.top());
        num.pop();
    }
    return ans;
}
```
