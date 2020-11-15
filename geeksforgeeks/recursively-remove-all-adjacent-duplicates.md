Wrong Solution ; Only Works for single level
```cpp
#include <iostream>
#include <string>
using namespace std;

string solve(const string& input, int pos) {
    if(pos == input.size())
        return "";
    if(pos + 1 == input.size() or input[pos] != input[pos+1])
        return input.substr(pos, 1) + solve(input, pos + 1);
    if(pos + 2 == input.size() or input[pos] != input[pos+2])
        return solve(input, pos + 2);
    return solve(input, pos + 1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        cout << solve(input, 0) << "\n";
    }
}
```
