```cpp
 
int student_req(vector<int> & A, int pages) {
    int student = 1;
    int sum = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] > pages)
            return INT_MAX;
        if(sum + A[i] > pages) {
            ++student;
            sum = A[i];
        }
        else {
            sum += A[i];
        }
    }
    return student;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(n < B)
        return -1;
    long long sum = 0;
    for(auto & x: A)
        sum += x;
    long long low = 0, high = sum, mid;
    int ans = INT_MAX;
    while(low <= high) {
        mid = low + (high - low >> 1);
        if(student_req(A, mid) <= B) {
            high = mid - 1;
            ans = min(ans, (int)mid);
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
```
