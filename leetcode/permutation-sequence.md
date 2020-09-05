```cpp
class Solution {
    vector<int> data;
public:
    int fact(int i) {
        if(i == 0 || i == 1)
            return 1;
        if(data[i] != -1)
            return data[i];
        return data[i] = i*fact(i-1);
    }
    string getPermutation(int n, int k) {
        data.resize(n+1, -1);
        string ans;
        for(int i = 1; i <= n; ++i)
            ans.push_back('0'+i);
        int f = n - 1;
        k--; // 0-based indexing
        for(int i = 0; i < n - 1; ++i) {
            int pos = k / fact(f);
            int j = i + pos;
            int target = ans[j];
            while(j > i) {
                ans[j] = ans[j-1];
                j--;
            }
            ans[i] = target;
            k %= fact(f--);
        }
        return ans;
    }
};

```
```cpp
class Solution {
    vector<int> data;
public:
    int fact(int i) {
        if(i == 0 || i == 1)
            return data[i] = 1;
        if(data[i] != -1)
            return data[i];
        return data[i] = i*fact(i-1);
    }
    string getPermutation(int n, int k) {
        data.resize(n+1, -1);
        vector<int> nums(n+1, 0);
        for(int i = 1; i< nums.size(); ++i)
            nums[i] = i;
        k -= 1;
        int f = n - 1;
        for(int i = 1; i + 1 < nums.size(); ++i) {
            int pos = k/fact(f);
            int j = i + pos;
            int target = nums[j];
            while(j > i) {
                nums[j] = nums[j-1];
                --j;
            }
            nums[i] = target;
            k %= fact(f--);
        }
        string ans;
        for(int i = 1; i < nums.size(); ++i)
            ans.push_back('0'+nums[i]);
        return ans;
    }
};
```
