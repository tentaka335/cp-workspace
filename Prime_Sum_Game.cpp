#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    set<ll> prime;
  for(ll i = 2;i<200;i++) {
    bool isprime = true;
    for(ll j = 2;j*j<=i;j++) {
        if(i%j==0)  {
            isprime = false;
            break;
        }
    }
    if(isprime) prime.insert(i);
  }
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  bool aoki;
  for(ll i = a;i<=b;i++) {
    bool takahashi = true;
    for(ll j = c;j<=d;j++) {
        if(prime.count(i+j)) {
            takahashi = false;
            continue;//青木が勝つ
        }
    }
    if(takahashi == true) {
        cout << "Takahashi" << "\n";
        return 0;
    }

  }
  cout << "Aoki";

    
    return 0;
}