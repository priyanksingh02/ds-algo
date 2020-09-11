```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        int imin = 0;
        int imax = m;
        while(imin <= imax) {
            int i = (imax + imin)/2;
            int j = (m + n + 1)/2 - i;
            int aleft = (i == 0)?INT_MIN:nums1[i-1];
            int aright = (i == m)?INT_MAX:nums1[i];
            int bleft = (j == 0)?INT_MIN:nums2[j-1];
            int bright = (j == n)?INT_MAX:nums2[j];
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
                    return ((double)max(aleft,bleft) + min(aright,bright))/2;
                }
            }
        }
        assert(false);
        return 0;
    }
};
```
