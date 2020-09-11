```cpp

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    int m = A.size();
    int n = B.size();
    if(m > n) {
        return findMedianSortedArrays(B, A);
    }
    if(m == 0) {
        if(n&1) {
            return B[n/2];
        }
        else {
            int mid = n/2;
            return ((double)B[mid-1] + B[mid])/2;
        }
    }
    int low = 0;
    int high = m;
    while(low <= high) {
        int mid = low + (high - low >> 1);
        int partA = mid;
        int partB = (m + n + 1)/2 - partA;
        
        int leftA = (partA > 0)?A[partA-1]:INT_MIN;
        int leftB = (partB > 0)?B[partB-1]:INT_MIN;
        
        int rightA= (partA < m)?A[partA]:INT_MAX;
        int rightB = (partB < n)?B[partB]:INT_MAX;
        
        if(leftA <= rightB && leftB <= rightA) {
            if(m + n & 1) {
                return max(leftA, leftB);
            }
            else {
                return ((double)max(leftA,leftB)+min(rightA,rightB))/2;
            }
        }
        if(leftA > rightB) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return 0.0; //unreachable
    
}
```

Same as above but concise.

```cpp

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {

    int m = A.size();
    int n  = B.size();
    if(m > n)
        return findMedianSortedArrays(B, A);
    int imin = 0;
    int imax = m;
    while(imin <= imax) {
        int i = imin + (imax - imin)/2;
        int j = (m + n + 1)/2 - i;
        int aleft = (i==0)?INT_MIN:A[i-1];
        int aright = (i==m)?INT_MAX:A[i];
        int bleft = (j==0)?INT_MIN:B[j-1];
        int bright = (j==n)?INT_MAX:B[j];
        if(aleft > bright) {
            imax = i - 1;
        }
        else if(bleft > aright) {
            imin = i + 1;
        }
        else {
            if(m+n & 1) {
                return max(aleft, bleft);
            }
            else {
                double ans = max(aleft,bleft);
                ans += min(aright, bright);
                return ans/2;
            }
        }
    }
    return 0; //unreachable
    
}
```
