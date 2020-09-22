```cpp
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
   int n = intervals.size();
   int i = 0;
   vector<Interval> ans;
   while(i < n && intervals[i].end < newInterval.start) {
       ans.push_back(intervals[i++]);
   }
   if(i == n) {
       ans.push_back(newInterval);
       return ans;
   }
    newInterval.start = min(newInterval.start, intervals[i].start);
    while(i < n && intervals[i].end <= newInterval.end) {
        i++;
    }
    if(i == n) {
        ans.push_back(newInterval);
        return ans;
    }
    if(newInterval.end < intervals[i].start) {
        ans.push_back(newInterval);
    }
    else {
        newInterval.end = intervals[i].end;
        ans.push_back(newInterval);
        ++i;
    }
    
    while(i < n) {
        ans.push_back(intervals[i++]);
    }
    return ans;
}
```
