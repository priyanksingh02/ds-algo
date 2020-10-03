Naive - TLE
```cpp
class MedianFinder {
    vector<int> nums;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int j = (int)nums.size();
        nums.push_back(num);
        while(j > 0 and nums[j] < nums[j-1]) {
            swap(nums[j], nums[j-1]);
            j--;
        }
    }
    
    double findMedian() {
        int n = nums.size();
        if(nums.empty())
            return 0;
        if(n&1) {
            return nums[n/2];
        }
        else {
            int pos = (n-1)/2;
            double ans = nums[pos];
            ans += nums[pos+1];
            return ans/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
