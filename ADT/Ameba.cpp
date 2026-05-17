#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
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
    
    ll n;
    cin >> n;
    vector<ll> B(2*n+1,inf);
    B[1] = 0;
   for(ll i = 1;i<=n;i++) {
    ll a;
    cin >> a;
    B[2*i] = B[a]+1;
    B[2*i+1] = B[a] + 1;
   }
   for(ll i =1;i<=2*n+1;i++) {
    cout << B[i] << "\n";
   }
    return 0;
}