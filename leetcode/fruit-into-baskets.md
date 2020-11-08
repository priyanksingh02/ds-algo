```cpp
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int baga = -1, acap = 0, bagb = -1, bcap = 0;
        int i = 0, j = 0;
        int ans = 0;
        while(j < tree.size()) {
            if(baga == -1 || baga == tree[j]) {
                baga = tree[j];
                acap++;
            }
            else if(bagb == -1 || bagb == tree[j]) {
                bagb = tree[j];
                bcap++;
            }
            else {
                while(i <= j && baga != -1 && bagb != -1) {
                    if(baga == tree[i] && --acap == 0) {
                        baga = -1;
                    }
                    else if(bagb == tree[i] && --bcap == 0) {
                        bagb = -1;
                    }
                    i++;
                }
                if(baga == -1) {
                    baga = tree[j];
                    acap++;
                }
                else {
                    bagb = tree[j];
                    bcap++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        ans = max(ans, j-i);
        return ans;
    }
};
```

