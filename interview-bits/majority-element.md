```cpp
int Solution::majorityElement(const vector<int> &A) {
    int major = -1, freq = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(freq == 0) {
            freq += 1;
            major = A[i];
        }
        else if(major == A[i]) {
            freq += 1;
        }
        else { // major != A[i]
            if(--freq < 0) {
                freq = 0;
                major = -1;
            }
        }
    }
    return major;
}
```
