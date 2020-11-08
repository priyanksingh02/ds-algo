```cpp
class Solution {
public:
    bool valid(vector<int> & v) {
        int h = v[0]*10+v[1];
        int m = v[2]*10+v[3];
        return 0<= h && h < 24 && 0<= m && m < 60;
    }
    
    string convert(vector<int> & v) {
        int h = v[0]*10+v[1];
        int m = v[2]*10+v[3];
        string hh, mm ;
        if( h <= 9 ) 
            hh.push_back('0');
        hh += to_string(h);
        if( m <= 9 )
            mm.push_back('0');
        mm += to_string(m);
        return hh + ":" + mm;
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string ans;
        do {
            if(valid(arr)) {
                ans = convert(arr);
            }
        }while(next_permutation(arr.begin(),arr.end()));
        return ans;
    }
};
```

