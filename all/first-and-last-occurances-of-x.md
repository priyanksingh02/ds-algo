```cpp
vector<int> find(int arr[], int n , int x )
{
    auto lb = lower_bound(arr, arr+n, x);
    auto ub = upper_bound(arr, arr+n, x);
    if(lb == ub)
        return {-1,-1};
    else 
        return {lb-arr, ub-arr-1};
}
```
