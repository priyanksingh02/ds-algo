```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        int i =0, j = 0;
        int n = input.size();
        vector<int> cnt(26, 0);
        int maxlen = 0;
        while(j < n) {
            cnt[input[j]-'a']++;
            while(i <= j && cnt[input[j]-'a'] > 1) {
                cnt[input[i] - 'a']--;
                i++;
            }
            maxlen= max(maxlen, j - i + 1);
            j++;
        }
        cout << maxlen << "\n";
    }
}

```
