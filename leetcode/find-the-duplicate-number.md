O(n) Without modification in given array
```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      // floyd cycle finding algorithm - similar to fast slow in linked list
      int fast = nums[0], slow = nums[0];
      do {
        fast = nums[nums[fast]];
        slow = nums[slow];
      }while(fast != slow);
      fast = nums[0];
      while(fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
      }
      return slow;
    }
};
```

O(nlogn) Without modification in given array
```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int low = 1;
      int high = (int)nums.size() - 1;
      while(low < high) {
        int mid = low + (high - low >> 1);
        int cnt = 0;
        for(int x: nums) {
          if(x <= mid)
            ++cnt;
        }

        if(cnt <= mid)
          low =mid+1;
        else
          high = mid;
      }
      return low;
    }
};

```

O(n) Time With modifications in given Array
```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      for(int i = 0; i< n; ++i) {
        int pos = abs(nums[i]);
        if(nums[pos] < 0)
          return pos;
        nums[pos] = -nums[pos];
      }
      return -1;
    }
};
```


```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      for(int i =0; i < n; ++i) {
        int cur = nums[i]%n;
        if(nums[cur] > n)
          return cur;
        else
          nums[cur] += n;
      }
      return 0; // dummy
    }
};
```

O(n) with additional O(n) space
```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      unordered_set<int> seen;
      for(int x: nums) {
        if(!seen.insert(x).second)
          return x;
      }
      return 0; // dummy
    }
};

```
