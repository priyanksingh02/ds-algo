```cpp
class MovingAverage {
  queue<int> q;
  int total;
  double sum;
  public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    total = size;
    sum = 0;
  }

  double next(int val) {
    q.push(val);
    sum += val;
    if(q.size() > total) {
      sum -= q.front();
      q.pop();
    }
    return sum/q.size();
  }
};
```
