```cpp
class CombinationIterator {
    string input;
    vector<int> iter;
    int diff;
public:
    CombinationIterator(string characters, int combinationLength) {
        input = characters;
        iter.resize(combinationLength);
        assert(combinationLength <= input.size());
        for(int i = 0; i < iter.size(); ++i) {
            iter[i] = i;
        }
        diff = input.size() - combinationLength;
        iter.back()--; // place iterator before last position
    }
    
    string next() {
        for(int i = iter.size() - 1; i >= 0; --i) {
            if(iter[i] + 1 - i <= diff) {
                iter[i] += 1;
                for(int j = i+1; j < iter.size(); ++j) {
                    iter[j] = iter[j-1] + 1; 
                }
                break;
            }
        }
        string ans;
        for(int i = 0; i < iter.size(); ++i) {

            ans += input[iter[i]];
        }
        return ans;
    }
    
    bool hasNext() {
        for(int i = iter.size() - 1; i >= 0; --i) {
            if(iter[i] + 1 - i <= diff) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

```

Same idea as above. optimized.

```cpp

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
      n = characters.size();
      k = combinationLength;
      s = characters;
      nums.resize(k);
      iota(nums.begin(), nums.end(), 0);
      has_next = true;
    
    }
    
    string next() {
      int i = k-1;
      string rsl;
      for (int j  = 0; j < k; ++j) {
        rsl += s[nums[j]];  
      }
      while (i >= 0 && nums[i] == n-k+i) --i;
      if (i >= 0) {
        nums[i]++;
        for (int j = i+1; j < k; ++j) {
          nums[j] = nums[i] + (j-i);
        }
      } else {
        has_next = false;
      }
      return rsl;
    }
    
    bool hasNext() {
      return has_next; 
    }
    
    bool has_next;
    int n;
    int k;
    vector<int> nums;
    string s;
  
};
```
