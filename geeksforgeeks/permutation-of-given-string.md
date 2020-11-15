```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        sort(input.begin(), input.end());
        do{
            cout << input << " ";
        }while(next_permutation(input.begin(), input.end()));
    }
    cout << "\n";
    
}
```
