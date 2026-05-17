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

using mint = modint998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<mint>> DP(3,vector<mint>(n+1));

    rep(i,n) {
        ll c = s[i] - 'a';

        rep(j,3) DP[j][i+1] = DP[j][i];
        rep(j,3) {
            if(j!=c) {
                DP[c][i+1] +=DP[j][i];
            }
        }
        DP[c][i+1]++;
    }
    mint ans =  DP[0][n] + DP[1][n] + DP[2][n];

    cout <<ans.val();
    return 0;
}