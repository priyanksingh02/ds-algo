```cpp
class Solution {
public:
    string nextClosestTime(string time) {
        vector<bool> digits(10, false);
        for(int i = 0; i < time.size(); ++i) {
            if(i == 2)
                continue;
            digits[time[i] - '0'] = true;
        }
        // Minimum Index
        int idx = 0;
        for(;idx < 10; ++idx) {
            if(digits[idx])
                break;
        }
        for(int i = time[4] - '0' + 1; i < 10; ++i) {
            if(digits[i]) {
                time[4] = '0'+i;
                return time;
            }
        }
        time[4] = '0'+idx;
        for(int i = time[3] - '0' + 1; i < 6; ++i) {
            if(digits[i]) {
                time[3] = '0'+i;
                return time;
            }
        }
        time[3] = '0'+idx;
        if(time[0] == '2') {
            for(int i = time[1] - '0' + 1; i < 4; ++i) {
                if(digits[i]) {
                    time[1] = '0'+i;
                    return time;
                }
            }
        }
        else { // 0 - 9 possible
            for(int i = time[1] - '0' + 1; i < 10; ++i) {
                if(digits[i]) {
                    time[1] = '0'+i;
                    return time;
                }
            }
        }
        time[1] = '0' + idx;
        for(int i = time[0] - '0' + 1; i <= 2; ++i) {
            if(digits[i]) {
                time[0] = '0'+i;
                return time;
            }
        }
        time[0] = '0' + idx;
        return time;
    }
};

```

