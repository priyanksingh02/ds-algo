```cpp
vector<long long> reverseInGroups(vector<long long> mv, int n, int k){
    int i = 0;
    for(; i + k < mv.size(); i+= k) {
        reverse(mv.begin() + i, mv.begin() + i + k);
    }
    reverse(mv.begin() + i, mv.end());
    return mv;
}
```

