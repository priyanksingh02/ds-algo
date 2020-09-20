```cpp
#include <list>
 
unordered_map<int, pair<int, list<int>::iterator>> m;
list<int> l;
int c;
 
LRUCache::LRUCache(int ca) {
    c = ca;
    m.clear();
    l.clear();
}
 
int LRUCache::get(int key) {
    auto it = m.find(key);
    if(it == m.end())
        return -1;
    else {
        l.splice(l.begin(),l,it->second.second);
        return it->second.first;
    }
}
 
void LRUCache::set(int key, int value) {
    auto it = m.find(key);
    if(it == m.end()) {
        if(m.size() == c) {
            m.erase(l.back());
            l.pop_back();
        }
        l.push_front(key);
        m[key] = make_pair(value,l.begin());
    }
    else {
        it->second.first = value;
        l.splice(l.begin(),l, it->second.second);
    }
}

```
```cpp
#include <list>
unordered_map<int, list<pair<int,int>>::iterator> m;
list<pair<int,int>> l;
int cap;

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    m.clear();
    l.clear();
}

// void print() {
//     cout << "map :";
//     for(auto & x: m) {
//         cout << x.first << " -> " << x.second->first << ", " << x.second->second << "; ";
//     }
//     cout << "\n List : ";
//     for(auto & x: l) {
//         cout << x.first << ", " << x.second << "; ";
//     }
//     cout <<endl;
// }

int LRUCache::get(int key) {
    int ans = 0;
    if(m.count(key)) {
        auto it = m[key];
        l.splice(l.end(), l, it);
        ans =  it->second;
    }
    else {
        ans =  -1;
    }
    // cout << "get : " << key << "ans : " << ans << endl;
    // print();
    return ans;
}

void LRUCache::set(int key, int value) {
    if(m.count(key)) {
        auto it = m[key];
        it->second = value;
        l.splice(l.end(), l, it);
    }
    else {
        l.push_back({key, value});
        m[key] = --l.end();
        if(l.size() > cap) {
            int er = l.begin()->first;
            l.pop_front();
            m.erase(er);
        }
    }
    // cout<< "set : " << key << " " << value << endl;
    // print();
}
```
