TLE. 
NOTE: A great way to generate Binary Pattern.
1, 10, 11, 100, 101, 110, 111, 1000, ....
```cpp

string Solution::multiple(int A) {
    queue<string> q;
    q.push("1");
    while(true) {
        auto & p = q.front(); q.pop();
        if(stol(p)%A == 0)
            return p;
        q.push(p+"0");
        q.push(p+"1");
    }
}
```
