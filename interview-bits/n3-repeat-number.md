```cpp

int Solution::repeatedNumber(const vector<int> &A) {
   int a, afreq, b, bfreq;
   afreq = bfreq = 0;
   a = b = -1;
   for(int i = 0; i < A.size(); ++i) {
       
       if(A[i] == a) {
           ++afreq;
       }
       else if(A[i] == b) {
           ++bfreq;
       }
       else if(a == -1) {
           a = A[i];
           afreq = 1;
       }
       else if(b == -1) {
           b = A[i];
           bfreq = 1;
       }
       else {
           if(--afreq == 0)
                a = -1;
            if(--bfreq == 0)
                b = -1;
       }
   }
    int n = A.size();
    afreq = bfreq = 0;
    for(int i = 0; i < n; ++i) {
        afreq += (A[i] == a);
        bfreq += (A[i] == b);
    }
    if(afreq > n/3 or bfreq > n/3)
        return (afreq > bfreq)?a:b;
    return -1;
}
```
