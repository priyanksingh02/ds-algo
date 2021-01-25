// 6 2 5 1 7 4 8 3
// answer: 2 5 7 8
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = { 6, 2, 5, 1, 7,4,8,3};

    vector<int> length (numbers.size() , 0);
    int n = numbers.size();

    for(int k = 0; k < n; ++k) {
        length[k] = 1;
        for(int i = 0; i < k; ++i) {
            if(numbers[i] < numbers[k])
                length[k] = max(length[k], length[i]+1);
        }
    }

    cout << *max_element(begin(length), end(length)) << endl;
}
