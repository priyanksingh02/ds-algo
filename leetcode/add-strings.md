```cpp
class Solution {
public:
    string add(const string & a, const string & b) {
        int carry = 0;
        int i = 0, j = 0;
        string ans;
        while(i < a.size() or j < b.size() or carry) {
            int sum = carry;
            if(i < a.size())
                sum += a[i++] - '0';
            if(j < b.size())
                sum += b[j++] - '0';
            ans.push_back(sum%10 + '0');
            carry = sum/10;
        }
        while(!ans.empty() and ans.back() == '0')
            ans.pop_back();
        if(ans.empty())
            return "0";
        return ans;
    }
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        auto ans = add(num1, num2);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
