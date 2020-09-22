```cpp

string Solution::largestNumber(const vector<int> &A) {
    vector<string> nums;
    for(auto & x: A)
        nums.push_back(to_string(x));
    sort(nums.begin(), nums.end(), [](const string& a,const string&b) {
        return a + b > b + a;
    });
    string ans;
    for(auto & x: nums)
        ans += x;
    // remove leading zeroes
    int i = 0;
    while(i < ans.size() && ans[i] =='0')
        i++;
    if( i == ans.size())
        return "0";
    return ans.substr(i);
}
```
