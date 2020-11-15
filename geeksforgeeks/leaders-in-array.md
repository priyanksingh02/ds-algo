```cpp
vector<int> leaders(int arr[], int n){
    int cur_max = -1;
    vector<int> ans;
    for(int i= n-1; i >= 0; --i) {
        cur_max = max(cur_max, arr[i]);
        if(cur_max == arr[i])
            ans.push_back(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

```

