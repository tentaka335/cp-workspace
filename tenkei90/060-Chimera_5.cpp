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
    vector<ll> A(n);
    vector<ll> L(300009,inf),R(300009,inf);
    vector<ll> dp(300009),dp2(300009);
    rep(i,n) cin >> A[i];
    rep(i,n) {
        ll pos = lower_bound(all(L),A[i]) - L.begin();
        L[pos] = A[i];
        dp[i] = pos+1; 
    }
    reverse(all(A));
    rep(i,n) {
        ll pos = lower_bound(all(R),A[i]) - R.begin();
        R[pos] = A[i];
        dp2[i] = pos+1; 
    }
    ll ans = 0;
    for(ll i = 0;i<n;i++) {
        chmax(ans,dp[i] + dp2[n-i-1] - 1);
    }
    cout << ans << "\n";
    
    

    
    return 0;
}