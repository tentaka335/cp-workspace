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
    
    ll n;
    cin >> n;
    ll ans = 0;
    ll asum = 0;
    vector<ll> A(n),B(n);
    rep(i,n) {
        cin >> A[i] >> B[i];
        asum +=A[i];
    }
    rep(i,n) {
        chmax(ans,asum - A[i] + B[i]);
    }
    cout << ans << "\n";
    
    
    return 0;
}