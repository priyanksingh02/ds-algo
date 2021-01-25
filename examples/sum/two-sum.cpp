#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool find(const vector<int> & nums, int sum) {
    int i = 0, j = nums.size() -1 ;
    while(i < j) {
        int csum = nums[i] + nums[j];
        if(csum == sum) {
            return true;
        } else if (csum < sum)
            i++;
        else
            j--;
    }
    return false;
}

int main() {
    vector<int> nums = { 1, 6, 2, 4, 2, 19, 40 , 10, 9 , 9 , 5};
    sort(nums.begin() , nums.end() );
    cout << find(nums, 19) << endl;
    cout << find(nums, 199) << endl;
}
