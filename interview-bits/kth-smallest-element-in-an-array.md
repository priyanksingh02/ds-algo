```cpp
int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int> pq;
    for(auto & x: A) {
        pq.push(x);
        if(pq.size() > B)
            pq.pop();
    }
    return pq.top();
}
```
