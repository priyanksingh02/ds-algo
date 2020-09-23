```cpp
class RandomizedSet {
    unordered_map<int, int> pos;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(pos.count(val))
            return false;
        nums.push_back(val);
        pos[val] = (int)nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!pos.count(val)) {
            return false;
        }
        pos[nums.back()] = pos[val];
        swap(nums[pos[val]], nums.back());
        nums.pop_back();
        pos.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand()%nums.size();
        return nums[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 ```
