```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0, j = 0;
        int carry = 0;
        string ans;
        while(i < a.size() || j < b.size() || carry) {
            int sum = carry;
            if(i < a.size())
                sum+= a[i++]-'0';
            if(j < b.size())
                sum+= b[j++]-'0';
            ans.push_back(sum%2 + '0');
            carry = sum/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
