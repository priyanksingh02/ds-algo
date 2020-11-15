# Stock buy and sell
```cpp
void stockBuySell(int prices[], int n)
{
    vector<pair<int,int>> ans;
    for(int i = 1; i < n; ++i) {
        if(prices[i] > prices[i-1]) {
            if(!ans.empty() and ans.back().second == i-1)
                ans.back().second = i;
            else
                ans.push_back(make_pair(i-1, i));
        }
        else if(!ans.empty() and prices[i] == prices[i-1] and i-1 == ans.back().second) {
            ans.back().second = i;
        }
    }
    if(ans.empty())
        cout << "No Profit";
    for(auto & p: ans) {
        cout << "(" << p.first << " " << p.second <<  ") ";
    }
}

```
