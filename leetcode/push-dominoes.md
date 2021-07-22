```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = dominoes.size();
        string ans = dominoes;
        int low = 0, high = l-1;
        bool onlydots = true;
        // ....L
        // ....R (ignore)
        for(int i = 0; i < l; ++i) {
            if(dominoes[i] != '.') {
                if(dominoes[i] == 'L') {
                    for(int k = 0; k < i; ++k) {
                        ans[k] = 'L';
                    }
                }
                low = i;
                onlydots = false;
                break;
            }
        }
        // L.... (ignore)
        // R.... 
        for(int i = l - 1; i >= 0; --i) {
            if(dominoes[i] != '.') {
                if(dominoes[i] == 'R') {
                    for(int k = l-1; k > i; --k) {
                        ans[k] = 'R';
                    }
                }
                high = i;
                onlydots = false;
                break;
            }
        }
        // R...R or L...L ==> fill same
        // R...L          ==> divide equally
        // L...R          ==> ignore
        if(onlydots) {
            return dominoes;
        }
        char left = '.', right = '.';
        for(int i = low; i<= high;) {
            assert(dominoes[i] != '.');
            left = dominoes[i];
            int j = i + 1;
            while(j <= high and dominoes[j] == '.') {
                j++;
            }
            right = dominoes[j];
            if(i + 1 == j) { // if no dots in between
                i = j;
                continue;
            }
            if(left == right) {
                for(int k = i+1; k < j; ++k) {
                    ans[k] = left;
                }
            }
            else if(left == 'R' and right == 'L') {
                int count = j - i - 1; // number of dots
                for(int k = 0; k < count/2; ++k) {
                    ans[k + i + 1] = left;
                }
                for(int k = count/2 - 1; k >= 0; --k) {
                    ans[j - 1 - k] = right;
                }
            }
            i = j; // move i to j
        }
        return ans;
    }
};

```
