```cpp
int MissingNumber(vector<int>& array, int n) {
    for(int i = 0; i< array.size(); ++i) {
        int number = abs(array[i]);
        if(number < n) {
            array[number-1] *= -1;
        }
    }
    int k = 0;
    for(; k < array.size(); ++k) {
        if(array[k] > 0)
            return k+1;
    }
    return k+1;
}
```
