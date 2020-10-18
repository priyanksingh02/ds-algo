Imagine a curve of gas usage at each stop;
start with zero gas;
                          /
--.                      /
   \                    /
    \        /"\       /
     ""\    /   \     /
        \__/     \   /
                  \_/ <- "A"

Condition for -1:              
If total usage reaches 0 or higher, then only it is possible to complete the trip


Condition for start pos:
The first gas station with positive diff and which comes after the global minima.

If we start at "A", all the required gas value will be positive and we will be able to finish the entire Trip.
```cpp
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int gas = 0, lowestgas = 0;
    int start = 0;
    for(int i = 0; i < n; ++i) {
        gas += A[i] - B[i];
        if(gas < lowestgas) {
            start = -1;
        }
        else if(gas > lowestgas && start == -1) {
            start = i;
        }
        lowestgas = min(gas, lowestgas);
    }
    if(gas < 0)
        return -1;
    return start;
}
```
O(n)
```cpp
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int sumGas = 0;
    int sumCost = 0;
    int start = 0;
    int tank = 0;
    for (int i = 0; i < gas.size(); i++) {
        sumGas += gas[i];
        sumCost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    if (sumGas < sumCost) {
        return -1;
    } else {
        return start;
    }
}
```
O(n^2)
```cpp
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    for(int i = 0; i < A.size(); ++i)  {
        if(A[i] - B[i] < 0)
            continue;
        int fuel = A[i] - B[i];
        int j = (i + 1)%A.size();
        while(fuel >= 0 && j != i) {
            fuel += A[j] - B[j];
            j = (j+1)%A.size();
        }
        if(fuel >= 0 and j == i)
            return i;
    }
    return -1;
}
```
