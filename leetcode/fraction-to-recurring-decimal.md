```cpp
class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string ans;
        bool sign = (n < 0) ^ (d < 0);
        if(sign)
            ans += "-";
        long num = n;
        if(num < 0) num = -num;
        if(num == 0)
            return "0";
        long den = d;
        if(den < 0) den = -den;
        ans += to_string(num/den);
        num %= den;
        if(num == 0)
            return ans;
        ans += ".";
        string frac;
        unordered_map<long,int> pos;
        pos[num] = 0;
        while(num) {
            num*= 10;
            frac += to_string(num/den);
            num%= den;
            if(pos.count(num)) {
                int p = pos[num];
                string rec;
                for(int i = 0; i < p && i < frac.size(); ++i) {
                    rec.push_back(frac[i]);
                }
                rec += "(";
                for(int i = p; i < frac.size(); ++i) {
                    rec.push_back(frac[i]);
                }
                rec += ")";
                frac = rec;
                break;
            }
            pos[num] = frac.size();
        }
        return ans+frac;
    }
};
```
