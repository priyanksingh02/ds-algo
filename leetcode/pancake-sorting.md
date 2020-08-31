```cpp
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans; // 1 based
        for(int i = (int)A.size() - 1; i >= 0; --i) {

            if(A[i] != i+1) {
                int j = i - 1;
                while(j >= 0 && A[j] != i+1) {
                    --j;
                }
                assert(j >= 0);
                if(j != 0) {
                    reverse(A.begin(), A.begin() + j+1);
                    ans.push_back(j+1);
                }
                reverse(A.begin(), A.begin() + i+1);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
```
