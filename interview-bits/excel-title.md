```cpp
string Solution::convertToTitle(int A) {
    string ans;
    while(A) {
        A-=1;
        ans.push_back((A)%26 + 'A');
        A/= 26;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
```
