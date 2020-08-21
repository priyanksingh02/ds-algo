```cpp

using ll = long long;
const int mod = 1e7 + 3;

ll possible(vector<int> & c, int board) {
    int count = 1;
    ll sum = 0;
    for(int i = 0; i < c.size(); ++i) {
        if(c[i] > board)
            return INT_MAX;
        if(sum + c[i] > board) {
            ++count;
            sum = c[i];
        }
        else {
            sum += c[i];
        }
    }
    return count;
}

int Solution::paint(int A, int B, vector<int> &C) {
    ll total = 0;
    for(auto & x: C) {
        total += x;
    }
    ll low = 1;
    ll high = total;
    ll ans = -1;
    while(low <= high) {
        int mid = low + (high - low >> 1);
        if(possible(C, mid) <= A) {
            high = mid -1;
            ans = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return (ans*B)%mod;
}
```
