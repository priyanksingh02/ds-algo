```cpp

#define ll long long
string Solution::fractionToDecimal(int a, int b) {
    ll A = abs((ll)a), B = abs((ll)b);
    string left, right, sign;
    unordered_map<int, int> um;
    
    sign = ((a >= 0 && b >= 0) || (a <= 0 && b <= 0)) ? "" : "-";
    left = to_string(A / B);
    A = A % B;
    while(A){
        if(um.find(A) == um.end())
            um[A] = right.size();
        else{
            right.insert(um[A], "(");
            right.push_back(')');
            break;
        }
        A = A * 10;
        right.push_back((A / B) + '0');
        A = A % B;
    }
    if(right.empty())
        return sign + left;
    return sign + left + "." + right;
}
```
