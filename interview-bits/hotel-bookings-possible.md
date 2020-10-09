```cpp

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int, bool>> time;
    for(int i = 0; i < arrive.size(); ++i) {
        time.push_back({arrive[i], true});
        time.push_back({depart[i], false});
    }
    sort(time.begin(), time.end());
    int cur = 0;
    for(int i = 0; i <  time.size(); ++i) {
        if(time[i].second) {
            ++cur;
        }
        else {
            --cur;
        }
        if(cur > K) {
            return false;
        }
    }
    return true;
}
```
