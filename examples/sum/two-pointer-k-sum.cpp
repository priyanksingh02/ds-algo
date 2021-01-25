#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ri,rj;

bool find(const vector<int> & nums, int sum) {
    int i = 0, j = 0;
    int cur_sum = 0;
    while(j < nums.size()) {
        cur_sum += nums[j];
        if(cur_sum > sum) {
            cur_sum-= nums[j];
            j--;
            cur_sum -= nums[i];
            i++;
            if(j < i) {
                cur_sum = 0;
                j = i;
                continue;
            }
        }
        if(cur_sum == sum) {
            ri = i;
            rj = j;
            return true;
        }
        j++;

    }
    return false;
}

int main() {
    vector<int> nums = { 20, 12, 1, 3, 2, 5, 1, 1, 2, 3};
    if(find(nums, 17)) {
        cout << "Found" << endl;
        for(int i = ri; i <= rj; ++i)
            cout << nums[i] << " ";
        cout << endl;
    }
    else
        cout << "Not found" << endl;
}
