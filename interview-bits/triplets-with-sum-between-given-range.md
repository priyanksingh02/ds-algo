```cpp
int Solution::solve(vector<string> &A) {
    double arr[3];
    if(A.size() < 3)
        return false;
    arr[0] = stod(A[0]);
    arr[1] = stod(A[1]);
    for(int i = 2; i < A.size(); ++i) {
        arr[2] = stod(A[i]);
        double sum = arr[0] + arr[1] + arr[2];
        if(sum - 2 > 1e-6) {
            // delete the largest number next time
            sort(arr, arr+3);
        }
        else if(sum - 1 < 1e-6) {
            sort(arr, arr+3, greater<double>());
        }
        else
            return true;
    }
    return false;
}
```
