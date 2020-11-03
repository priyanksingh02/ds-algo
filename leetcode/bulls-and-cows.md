```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) {
                ++bulls;
                secret[i] = '*';
                guess[i] = '#';
            }
        }
        unordered_map<char,int> m;
        int cows =  0;
        for(int i = 0; i < secret.size(); ++i) {
            m[secret[i]]++;
        }
        for(int i = 0; i < guess.size(); ++i) {
            if(m.count(guess[i])) {
                ++cows;
                if(--m[guess[i]] == 0) {
                    m.erase(guess[i]);
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```
