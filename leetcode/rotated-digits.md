```cpp
class Solution {
public:
    
    int good(int x) {
        string a = to_string(x);
        string ans;
        for(int i = 0; i < a.size(); ++i) {
            int c = a[i] - '0';
            switch(c) {
                case 3:case 4:case 7:
                    return 0;
                case 2: case 5:
                    ans.push_back(7 - c + '0'); break;
                case 6: case 9:
                    ans.push_back(15 - c + '0'); break;
                default:
                    ans.push_back(c + '0');break;
            }
        }
        return ans != a;
    }
    
    int rotatedDigits(int N) {
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            ans += good(i);
        }
        return ans;
    }
};
```

