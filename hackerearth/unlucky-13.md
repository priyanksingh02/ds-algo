Based on Matrix Exponentiation
Time: O(M^3 * log n)_
```cpp
#include<bits/stdc++.h>

#define ll long long
#define rep(i,k) for (int i = 0 ; i<k ; i++)

using namespace std;

ll n;

const int mod = 1e9+9;

struct Matrix{
  vector<vector<ll>>a = vector<vector<ll>>(2,vector<ll>(2,0));
  Matrix operator*(const Matrix& other){
    Matrix res;
    rep(i,2){
      rep(j,2){
        rep(k,2){
          res.a[i][k] += a[i][j] * other.a[j][k];
          res.a[i][k] %= mod;
        }
      }
    }
    return res;
  }
};

Matrix expo_power(Matrix single,ll p){
  Matrix id;
  rep(i,2)
    id.a[i][i] = 1;
  while (p>0){
    if (p & 1) id = id*single;
    single = single*single;
    p = p>>1;
  }
  return id;
}
void solve(){
  cin>>n;
  Matrix single;
  single.a[0][0] = 9;
  single.a[0][1] = 1;
  single.a[1][0] = 8;
  single.a[1][1] = 1;

  Matrix ans = expo_power(single,n);
  cout<<(ans.a[0][0] + ans.a[0][1])%mod<<endl;
}

int main(){
  int t;
  cin>>t;
  while (t--){
    solve();
  }
}
```
