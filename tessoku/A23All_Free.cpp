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
    
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> dp(m+1,vector<ll>(((ll)1)<<n,inf));
    vector<ll> A(m+1);
    ll S = ((ll)1)<<n ;
    S--;
    rep(i,m) {
        rep(j,n) {
            ll a;
            cin >> a;
            
            if(a==1) A[i+1] += (1<<j);
        }
    }
    for(ll j = 0;j<=m;j++) dp[j][0] = 0;

        for(ll j = 1;j<=m;j++) {
             for(ll i = 0;i<=S;i++) {
            dp[j][i] = min(dp[j][i],dp[j-1][i]);
            dp[j][i|A[j]] = min(dp[j][i|A[j]],dp[j-1][i] + 1);
             }
        }
    

    if(dp[m][S]  == inf) cout << -1 << "\n";
    else cout << dp[m][S] << "\n";


    
    return 0;
}