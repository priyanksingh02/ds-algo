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
