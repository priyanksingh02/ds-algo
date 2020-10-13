Two Heaps to always maintain median at top.
```cpp
class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() or left.top() >= num)
            left.push(num);
        else
            right.push(num);
        int l = left.size();
        int r = right.size();
        if(l == r or l == r+1) {
            // do nothing
        }
        else if(l > r) {
            right.push(left.top());
            left.pop();
        }
        else {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.empty())
            return 0;
        if(left.size() > right.size())
            return left.top();
        double ans = left.top();
        ans += right.top();
        return ans/2;
    }
};

```
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
```
