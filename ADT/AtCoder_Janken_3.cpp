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
    string s;
    cin >> s;
    vector<vector<ll>> dp(n+1,vector<ll>(3));
    if(s[0]=='P') { dp[1][0] = 0;dp[1][1] = -inf;dp[1][2] = 1;}
    if(s[0]=='R') {dp[1][0] = 1;dp[1][1] = 0;dp[1][2] = -inf;}
    if(s[0]=='S') {dp[1][0] = -inf;dp[1][1] = 1;dp[1][2] = 0;}
    for(ll i = 2;i<=n;i++) {
        if(s[i-1] == 'P') {
            dp[i][1] = -inf;
            dp[i][0] = max(dp[i-1][1],dp[i-1][2]);
            dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + 1; 
            }
        if(s[i-1] == 'R') {
            dp[i][2] = -inf;
            dp[i][1] = max(dp[i-1][2],dp[i-1][0]);
            dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + 1; 
        }
        if(s[i-1] == 'S') {
              dp[i][0] = -inf;
            dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = max(dp[i-1][2],dp[i-1][0]) + 1; 
        }
    }

    cout << max({dp[n][0],dp[n][1],dp[n][2]}) << "\n";

    return 0;
}