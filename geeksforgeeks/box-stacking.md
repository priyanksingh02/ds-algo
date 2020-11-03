```cpp
pair<int,int> compose(int a, int b) {
    if(a < b) return {a, b};
    else return {b, a};
}
int maxHeight(int height[],int width[],int length[],int n)
{
    vector<pair<pair<int,int>,int>> boxes;
    for(int i =0; i < n; ++i) {
        boxes.push_back({compose(height[i],width[i]), length[i]});
        boxes.push_back({compose(height[i],length[i]), width[i]});
        boxes.push_back({compose(width[i],length[i]), height[i]});
    }
    sort(boxes.begin(), boxes.end());
    // Increasing subsequence sum
    vector<int> dp(boxes.size(), 0);
    int maxheight = 0;
    for(int i = 0; i < boxes.size(); ++i) {
        dp[i] = boxes[i].second;
        for(int j = 0; j < i; ++j) {
            if(boxes[j].first.first < boxes[i].first.first && boxes[j].first.second < boxes[i].first.second)
                dp[i] = max(dp[i], dp[j] + boxes[i].second);
        }
        maxheight = max(maxheight, dp[i]);
    }
    return maxheight;
}
```

