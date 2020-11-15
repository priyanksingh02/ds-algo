#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
    sim > struct rge { c b, e; };
    sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
    sim > auto dud(c* x) -> decltype(cerr << *x, 0);
    sim > char dud(...);
    struct debug {
#ifdef LOCAL
      ~debug() { cerr << endl; }
      eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair < b, c > d) {
      ris << "(" << d.first << ", " << d.second << ")";
    }
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

void test_case() {
  vector<int> v = {1,2,3};
  vector<pair<int,int>> vp = {{2,3},{4,5}};
  map<int,int> m;
  m[1] = 5;
  m[2] = 4;
  debug() << imie(v) imie(vp) imie(m);
}

int main() {
  int T;
  scanf("%d", &T);
  debug() << imie(T);
  for(int nr = 1; nr <= T; ++nr) {
    printf("Case #%d: ", nr);
    test_case();
  }
}

