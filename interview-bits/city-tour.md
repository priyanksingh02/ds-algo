```cpp
const int M = 1e9 + 7;
int f[1010];

int fact(int a) {
  if(a == 0)
    return 1;
  if(f[a])
    return f[a];
  return f[a] = ((long)a*fact(a-1))%M;
}

long power(long a, int b) {
  long res = 1;
  while(b) {
      if(b&1) res = (res * a)%M;
    a = (a*a)%M;
    b>>=1;
  }
  return res;
}

int Solution::solve(int n, vector<int> & num) {
  sort(num.begin(), num.end());
  long ans = fact(n - num.size());
  for(int i = 1; i < num.size(); ++i) {
    int dif = num[i] - num[i-1]-1;
    if(dif > 0) {
        ans = (ans*power(fact(dif), M-2))%M;
        ans = (ans*power(2, dif-1))%M;
    }
  }
  ans = (ans*power(fact(n-num.back()), M-2))%M;
  ans = (ans*power(fact(num.front()-1),M-2))%M;
  return ans;
}
```
