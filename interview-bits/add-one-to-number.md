```cpp

vector<int> Solution::plusOne(vector<int> &a) {
    reverse(a.begin(),a.end());
    vector<int> ans;
    int carry = 1;
    int i = 0;
    while( i < a.size() || carry) {
        int sum = carry;
        if(i < a.size())
            sum += a[i++];
        ans.push_back(sum%10);
        carry = sum/10;
    }
    while(!ans.empty() and ans.back() == 0)
        ans.pop_back();
    if(ans.empty())
        return {0};
    reverse(ans.begin(),ans.end());
    return ans;
}
```
