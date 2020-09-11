```cpp
int Solution::search(const vector<int> &arr, int target) {
    if(arr.empty())
        return -1;
    int low = 0;
    int high = (int)arr.size() - 1;
    int front = arr.front();
    while(low <= high) {
        int mid = low + (high - low >> 1);
        if(arr[mid] == target)
            return mid;
        bool target_section = target>= front;
        bool mid_section = arr[mid] >= front;
        if(target_section == mid_section) {
            if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            if(mid_section) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
     
    return -1;   
}
```
