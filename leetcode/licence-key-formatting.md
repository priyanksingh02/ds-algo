
```cpp
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int cur = 0;
        for(int i = (int)S.size() -1 ; i >= 0; --i) {
            if(S[i] == '-')
                continue;
            if(isalpha(S[i]))
                ans.push_back(toupper(S[i]));
            else
                ans.push_back(S[i]);
            if(++cur == K) {
                ans.push_back('-');
                cur = 0;
            }
        }
        if(!ans.empty() && ans.back() == '-')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

