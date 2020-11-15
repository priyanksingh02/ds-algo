```cpp
string printLargest(vector<string> &arr) {
    sort(arr.begin(), arr.end(), [](const string & a, const string & b) {
            return a + b > b + a;
        });
    string res;
    for(auto & s: arr) {
        res += s;
    }
    return res;

}
```
