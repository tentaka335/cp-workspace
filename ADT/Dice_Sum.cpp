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
using mint = modint998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<mint>> dp(n+1,vector<mint>(k+1,0));//dp[i][j] = i文字目まででわがjのもの
    for(ll i = 1;i<=m;i++) dp[1][i] = 1;
    
    for(ll i = 2;i<=n;i++) {
        for(ll j = 1 ;j<=k;j++) {
            for(ll l = 1;l<=m;l++) {
                if(j-l>=0) dp[i][j] +=dp[i-1][j-l];
            }
        }
    }
    mint ans = 0;
    for(ll i = n;i<=k;i++) {
        ans += dp[n][i];
    }

    cout << ans.val() << "\n";
    return 0;

}