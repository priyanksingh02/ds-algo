```cpp
class Logger {
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        int t = timestamp - 10;
        if(m.count(message)) { 
            if(m[message] <= t) {
                m[message] = timestamp;
                return true;
            }
            else 
                return false;
        }
        else {
            m[message] = timestamp;
            return true;
        }
    }
};

```

