```cpp
class NumArray {
    vector<int> arr;
    vector<int> data;
    int n;
public:
    NumArray(vector<int>& nums) {
        if(nums.empty())
            return ;
        arr = nums;
        n = nums.size();
        int x = ceil(log2(n));
        int sz = 2*pow(2, x) - 1;
        data.resize(sz, 0);
        construct(0, 0, n-1);
    }
    
    int left(int i) { return i*2 + 1;}
    int right(int i) {return i*2 + 2;}
    
    int construct(int k, int low, int high) {
        if(low == high) {
            data[k] = arr[low];
        }
        else {
            int mid = low + (high-low)/2;
            data[k] = construct(left(k), low, mid) + construct(right(k), mid+1, high);
        }
        return data[k];
    }
    
    void update(int k, int low, int high, int i, int dif) {
        if(i < low or i > high)
            return;
        data[k] += dif;
        if(low != high) {
            int mid = low + (high - low >> 1);
            update(left(k), low, mid, i, dif);
            update(right(k), mid+1, high, i, dif);
        }
    }
    
    void update(int i, int val) {
        int dif = val - arr[i];
        arr[i] = val;
        update(0, 0, n-1, i, dif);
    }
    
    int sum(int k, int low, int high, int i, int j) {
        if(i <= low && j >= high)
            return data[k];
        else if(i > high or j < low)
            return 0;
        else {
            int mid = low + (high-low)/2;
            return sum(left(k), low, mid, i, j) + sum(right(k), mid+1, high, i, j);
        }
    }
    
    int sumRange(int i, int j) {
        return sum(0, 0, n-1, i, j);
    }
};
```

