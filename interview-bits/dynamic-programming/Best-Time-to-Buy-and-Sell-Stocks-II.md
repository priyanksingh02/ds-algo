## Reason: 

    2   4   6   Buying at 2 and selling at 6 can seen as
    Buying at 2 and selling at 4
    Buying at 4 and selling at 6

```cpp
int Solution::maxProfit(const vector<int> &A) {
    int profit = 0;
    for(int i = 1; i < A.size(); ++i) {
        profit += max(0, A[i] - A[i-1]);
    }
    return profit;
}

```
