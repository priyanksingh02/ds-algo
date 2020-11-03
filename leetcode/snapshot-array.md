```cpp
class SnapshotArray {
  vector<vector<pair<int,int>>> data;
  int id;
public:
    SnapshotArray(int length) {
      id = 0;
      data.resize(length,{ {0,0}});
    }
    
    void set(int index, int val) {
      auto & v = data[index];
      if(v.back().second == id)
        v.back().first = val;
      else {
        v.push_back({val, id});
      }
    }
    
    int snap() {
       return id++; 
    }
    
    int get(int index,int snap_id) {
       auto & v = data[index];
        int low = 0;
        int high = (int) v.size() -1 ;
        int ans = 0;
        while(low <= high) {
          int mid = low + (high - low)/2;
          if(v[mid].second <= snap_id) {
            ans = mid;
            low = mid + 1;
          }
          else {
            high = mid - 1; 
          } 
        }
       return v[ans].first; 
    }
};

```

