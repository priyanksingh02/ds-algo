```cpp
class Solution {
public:
    int numWays(string s) {
        int one = 0;
        const int mod = 1e9 + 7;
        int n = s.size();
        for(auto & c: s)
            one += (c == '1');
        if(one%3) // not divisible by 3
            return 0;
        if(!one) // count of '1' = 0
            return ((long long)(n-1)*(n-2)/2)%mod;
        int cur = 0;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; ++i) {
            cur += (s[i] == '1');
            if(cur == one/3)
                ++c1;
            if(cur == one*2/3)
                ++c2;
        }
        return (long long)c1*c2%mod;
    }       
};
```
