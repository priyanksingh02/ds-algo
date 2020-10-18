```cpp
class Fancy {
    long add, mul;
    vector<int> nums;
    const int mod = 1e9 + 7;
    int power(int a, int b) {
        long res = 1, k = a;
        while(b) {
            if(b & 1)
                res = (res*k)%mod;
            k = (k*k)%mod;
            b >>= 1;
        }
        return res;
    }
public:
    Fancy() {
        add = 0;
        mul = 1;
    }
    
    void append(int val) {
        val = ((long)val + mod - add)%mod;
        val = ((long)val * power(mul, mod - 2))%mod;
        nums.push_back(val);
    }
    
    void addAll(int inc) {
        add = (add + inc)%mod;
    }
    
    void multAll(int m) {
        add = (add * m)%mod;
        mul = (mul*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx >= nums.size())
            return -1;
        return ((long)nums[idx]*mul + add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
 ```
