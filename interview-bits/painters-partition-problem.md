```cpp
int process(int total, vector<int> & board) {
    int req = 1;
    int sum = 0;
    for(int i = 0; i< board.size(); ++i) {
        if(board[i] > total)
            return INT_MAX; // board can't be shared
        if(sum + board[i] > total) {
            sum = board[i];
            req++;
        }
        else {
            sum += board[i];
        }
    }
    return req;
}

int Solution::paint(int k, int b, vector<int> &C) {
    const int mod = 1e7 + 3;
    long sum = 0;
    for(auto & x: C)
        sum += x;
    long low = 1;
    long high = sum;
    while(low < high) {
        long mid = low + (high - low >> 1);
        if(process(mid, C) > k) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return (low*b)%mod;
}

```
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
