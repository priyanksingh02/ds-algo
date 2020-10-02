```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> aux;
        for(auto & x: nums)
            aux.push_back(to_string(x));
        sort(aux.begin(), aux.end(), [](string & a, string & b){
            return a + b > b + a;
        });
        string ans;
        for(auto & s: aux)
            ans += s;
        int i = 0;
        for(; i < ans.size(); ++i) {
            if(ans[i] != '0')
                break;
        }
        if(i == ans.size())
            return "0";
        return ans.substr(i);
    }
};
```
