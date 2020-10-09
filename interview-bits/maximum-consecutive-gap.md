O(n) using bucketing
```cpp
int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2) return 0;
    int ma=*max_element(A.begin(),A.end()),mi=*min_element(A.begin(),A.end()),n=A.size();
    double gap=(double)(ma-mi)/(n-1);
    vector<int>min_no(n-1,INT_MAX);
    vector<int>max_no(n-1,INT_MIN);
    for(int i=0;i<n;i++){
        int j=floor((A[i]-mi)/gap);
        if(A[i]==mi) j=0;
        else if(A[i]==ma) j=n-2;
        min_no[j]=min(min_no[j],A[i]);
        max_no[j]=max(max_no[j],A[i]);
    }
    int p=gap,a=max_no[0];
    for(int i=1;i<n-1;i++){
        if(max_no[i]==INT_MIN||min_no[i]==INT_MAX) continue;
        p=max(p,min_no[i]-a);
        a=max_no[i];
    }
    return p;
}
```
O(n logn)
```cpp

int Solution::maximumGap(const vector<int> &A) {
    int maxdif = 0;
    vector<int> B {A};
    sort(B.begin(), B.end());
    for(int i = 1; i < B.size(); ++i) {
        maxdif = max(maxdif, B[i] - B[i-1]);
    }
    return maxdif;
}
```
