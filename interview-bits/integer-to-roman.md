```cpp
string Solution::intToRoman(int A) {
    vector<pair<int, string>> mapping {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90,"XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    string ans;
    for(int i = 0; i < mapping.size(); ++i) {
        if(mapping[i].first <= A) {
            ans += mapping[i].second;
            A -= mapping[i].first;
            --i;
        }
    }
    return ans;
}
```
