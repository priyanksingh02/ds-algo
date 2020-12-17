// Bryce Adelstein Lelbach 's template for benchmarking timer
// Can be used for anything which takes time > micro seconds.
#include <bits/stdc++.h>
using namespace std;

struct high_res_timer {
  high_res_timer(): start_time_{take_time_stamp()} {}

  void restart() { start_time_ = take_time_stamp(); }

  // elapsed time in sec
  double elapsed() const { return double(take_time_stamp() - start_time_) * 1e-9; }

  uint64_t elapsed_nano() const { return take_time_stamp() - start_time_; }

  protected:
  static uint64_t take_time_stamp() { return uint64_t(chrono::high_resolution_clock::now().time_since_epoch().count()); };

  private:
  uint64_t start_time_;
};

int main() {
  high_res_timer timer;
  vector<int> arr = {2, 3, 5, 1, 3 , 5};
  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  cout << timer.elapsed() << endl;
}


