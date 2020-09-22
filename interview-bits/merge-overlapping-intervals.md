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
vector<Interval> Solution::merge(vector<Interval> &A) {
   vector<Interval> ans; 
    sort(A.begin(), A.end(), [](Interval a, Interval b){
        if(a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    });
   for(int i = 0; i < A.size(); ++i) {
       if(ans.empty() or ans.back().end < A[i].start)
            ans.push_back(A[i]);
        else {
            ans.back().start = min(ans.back().start, A[i].start);
            ans.back().end = max(ans.back().end, A[i].end);
        }
   }
   return ans;
}
```
