```cpp
#include<iostream>
#include<string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        int pos = -1;
        for(int i = (int)input.size() - 1; i >= 0; --i) {
            if(input[i] == '1') {
                pos = i;
                break;
            }
        }
        cout << pos << "\n";
    }
}

```
