### Cycle Finding algorithm - similar to linked list
```cpp
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}
```

### Bucket method - Solution Approach answer
```cpp
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    n -= 1;
    int sq = sqrt(n);
    int sz = ceil((double)n/sq);
    int lastlimit = sz*sq - n;
    // cout << n << " " << sq << " " << sz << " " << lastlimit << endl;
    vector<int> bucket(sz, 0);
    int bucketpos = -1;
    for(int i = 0; i < A.size(); ++i) {
        int pos = (A[i]-1)/sq;
        bucket[pos]++;
        if(pos + 1 == sz && lastlimit) {
            if(bucket[pos] > sq - lastlimit) {
                bucketpos = pos;
                break;
            }
        }
        else {
            if(bucket[pos] > sq) {
                bucketpos = pos;
                break;
            }
        }
    }
    // cout << "bucket .. ";
    // for(auto & x: bucket) {
    //     cout << x << " ";
    // }
    // cout << endl;
    if(bucketpos == -1) // no duplicates
        return -1;
    int lowlimit = bucketpos * sq + 1;
    int highlimit = (bucketpos + 1)* sq;
    // cout << bucketpos << " " << lowlimit << " " << highlimit << endl;
    bucket.clear();
    bucket.resize(sz, 0); // clear previous count
    for(int i= 0; i < A.size(); ++i) {
        if(A[i] >= lowlimit && A[i] <= highlimit) {
            bucket[A[i] - lowlimit]++;
            if(bucket[A[i] - lowlimit] > 1) {
                // cout << A[i] << "-" << lowlimit << "=" << A[i] - lowlimit << "->" << bucket[A[i]-lowlimit] << endl;
                return A[i];
            }
        }
    }
    return -1; //unreachable
}
```
