```cpp

class LRUCache {
    list<int> keys;
    unordered_map<int,pair<int,list<int>::iterator>> mapping;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mapping.count(key)) {
            keys.splice(keys.end(), keys, mapping[key].second);
            return mapping[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mapping.count(key)) {
            keys.splice(keys.end(), keys, mapping[key].second);
            mapping[key].first = value;
        }
        else {
            if(mapping.size() == cap) {
                mapping.erase(keys.front());
                keys.pop_front();
            }
            keys.push_back(key);
            auto iter = keys.end();
            mapping[key] = {value, --iter};
        }
    }
};
```
