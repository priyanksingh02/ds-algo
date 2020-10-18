```cpp
int Solution::numRange(vector<int> &A, int B, int C) {
    int sum=0,j=0,k=0,cnt=0,n=A.size();
    for(int i=0;i<A.size();i++){
        sum+= A[i];
        while(sum>C and k<n){
            sum-= A[k]; k++;
        }
        j = k;
        int temp = sum;
        while(temp>=B and j<n){
            temp-= A[j];
            j++;
        }
        cnt+= j-k;
    }
    return cnt;
}
```
