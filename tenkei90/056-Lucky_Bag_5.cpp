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
    
    ll n,s;
    cin >> n >> s;
    
    vector<ll> A(n+1),B(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<char>> dp(n+1,vector<char>(100009,'e'));
    dp[1][A[1]] = 'A',dp[1][B[1]] = 'B';
    for(ll i = 1;i<=n-1;i++) {
        for(ll j = 1;j<=s;j++) {
            if(dp[i][j] == 'e') continue;
            ll na = j+A[i+1];
            ll nb = j+B[i+1];
            if(1<=na&&na<=s) {
                dp[i+1][na] = 'A';
            }
            if(1<=nb&&nb<=s) {
                dp[i+1][nb] = 'B';
            }
        }
    }

    if(dp[n][s]=='e') {
        cout << "Impossible" << "\n";
        return 0;
    }
   vector<char> ans(n);
   ll pos = s;
   for(ll i = n;i>=1;i-- ) {
    ans[i] = dp[i][pos];
    if(ans[i]=='A') pos -=A[i];
    else pos -=B[i];
   }

   for(ll i = 1;i<=n;i++) cout << ans[i];
    return 0;
}